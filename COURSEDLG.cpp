// COURSEDLG.cpp: 实现文件
//

#include "pch.h"
#include "SmartLuoJia2.0.h"
#include "afxdialogex.h"
#include "COURSEDLG.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>



// COURSEDLG 对话框
IMPLEMENT_DYNAMIC(COURSEDLG, CDialogEx)

COURSEDLG::COURSEDLG(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_COURSE, pParent), m_currentWeek(1)
{
    // 默认开始日期为2025年2月16日(第一个星期日)
    m_startDate = CTime(2025, 2, 16, 0, 0, 0);
}

COURSEDLG::~COURSEDLG()
{
    // 释放背景画刷
    m_bgBrush.DeleteObject();
    FontGrid.DeleteObject();
}

void COURSEDLG::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);

    DDX_Control(pDX, IDC_COURSE_LAST, LastButton);
    DDX_Control(pDX, IDC_COURSE_NEXT, NextButton);
    DDX_Control(pDX, IDC_COURSE_SETTING, SettingButton);
    DDX_Control(pDX, IDC_COURSE_INPUT, InputButton);
    DDX_Control(pDX, IDC_COURSE_COMBO, WeekCombo);
    DDX_Control(pDX, IDC_COURSE_LIST, m_courseList);
    DDX_Control(pDX, IDC_COURSE_BACK, BackButton);
}

BEGIN_MESSAGE_MAP(COURSEDLG, CDialogEx)
    ON_WM_ERASEBKGND() // 背景相关
    ON_WM_CTLCOLOR()
    ON_WM_PAINT()
    ON_BN_CLICKED(IDC_COURSE_LAST, &COURSEDLG::OnBnClickedCourseLast)
    ON_BN_CLICKED(IDC_COURSE_NEXT, &COURSEDLG::OnBnClickedCourseNext)
    ON_BN_CLICKED(IDC_COURSE_SETTING, &COURSEDLG::OnBnClickedCourseSetting)
    ON_BN_CLICKED(IDC_COURSE_INPUT, &COURSEDLG::OnBnClickedCourseInput)
    ON_CBN_SELCHANGE(IDC_COURSE_COMBO, &COURSEDLG::OnCbnSelchangeCourseCombo)
    ON_BN_CLICKED(IDC_COURSE_BACK, &COURSEDLG::OnBnClickedCourseBack)
END_MESSAGE_MAP()

BOOL COURSEDLG::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // 初始化背景画刷
    m_bgBrush.CreateSolidBrush(RGB(39, 160, 134)); // 绿色背景

    // 初始化字体
    FontCommon.CreateFont(
        30, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0,
        ANSI_CHARSET, OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
        DEFAULT_PITCH | FF_SWISS, _T("微软雅黑"));

    FontGrid.CreateFont(
        16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0,
        ANSI_CHARSET, OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
        DEFAULT_PITCH | FF_SWISS, _T("微软雅黑"));

    // 设置此对话框的图标
    SetIcon(m_hIcon, TRUE);   // 设置大图标
    SetIcon(m_hIcon, FALSE);  // 设置小图标

    // 初始化周数下拉框
    if (WeekCombo.m_hWnd != nullptr)
    {
        WeekCombo.ResetContent();
        WeekCombo.AddString(_T("周数"));
        for (int i = 1; i <= 16; i++)
        {
            CString str;
            str.Format(_T("第%d周"), i);
            WeekCombo.AddString(str);
        }
        WeekCombo.SetCurSel(0);
    }
    // 初始化课程列表
    m_courseList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

    // 添加列
    CString days[] = { _T("节次"), _T("星期日"), _T("星期一"), _T("星期二"),
                      _T("星期三"), _T("星期四"), _T("星期五"), _T("星期六") };

    for (int i = 0; i < 8; i++)
    {
        m_courseList.InsertColumn(i, days[i], LVCFMT_CENTER, 100);
    }

    // 添加行(13节课)
    int count = 0;
    // 添加行(1-15节课，含午休和晚休标记)
   
    for (int i = 1; i <= 15; i++)
    {
        CString str;

        // 处理午休和晚休
        if (i == 6)
        {
            m_courseList.InsertItem(i - 1, _T("午休"));
            count++;
            continue;
        }
        else if (i == 11)
        {
            str.Format(_T("%d"), i - count);
            m_courseList.InsertItem(i - 1, str);
            m_courseList.InsertItem(i, _T("晚休"));
            count++;
            i++;
            continue;
        }

        // 普通节次显示（自动跳过已计数的休息时段）
        str.Format(_T("%d"), i - count);
        m_courseList.InsertItem(i - 1, str);
    }

    // 获取学号
    getInf();

    // 加载课程数据
    LoadCourseData();

    // 计算当前周
    CalculateCurrentWeek();

    // 显示当前周课程表
    DisplayCourseTable(m_currentWeek);

    m_courseList.SetColumnWidth(0, 60);  // 节次列
    for (int i = 1; i < 8; i++)
        m_courseList.SetColumnWidth(i, 240); // 课程列
    return TRUE;
}

BOOL COURSEDLG::OnEraseBkgnd(CDC* pDC)
{
    CRect rect;
    GetClientRect(&rect);
    pDC->FillRect(&rect, &m_bgBrush); // 填充背景色
    return TRUE; // 阻止默认背景绘制
}

HBRUSH COURSEDLG::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

    UINT nID = pWnd->GetDlgCtrlID();

    if (nID == IDC_COURSE_TOPIC)
    {

        pDC->SetTextColor(TextColor1);
        pDC->SetBkMode(TRANSPARENT);
        pDC->SelectObject(&FontCommon);
        return (HBRUSH)m_bgBrush;
    }
    else if (nID == IDC_COURSE_LIST)
    {
        // 默认样式
        pDC->SetTextColor(RGB(0, 0, 0));
        pDC->SetBkColor(RGB(255, 255, 255));
        pDC->SelectObject(&FontGrid);
        return (HBRUSH)::GetStockObject(WHITE_BRUSH);
    }

    return hbr;
}

void COURSEDLG::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this);
        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CPaintDC dc(this);
        // 绘制校徽
        {
            CImage imgLogo;
            if (SUCCEEDED(imgLogo.Load(L".\\res\\校徽.png")))
            {
                CRect rect;
                GetDlgItem(IDC_COURSE_BADGE)->GetWindowRect(&rect);
                ScreenToClient(&rect);
                dc.SetStretchBltMode(HALFTONE);
                imgLogo.Draw(dc.m_hDC, rect);
            }
        }

        CDialogEx::OnPaint();
    }
}

// 上一周
void COURSEDLG::OnBnClickedCourseLast()
{
    if (m_currentWeek > 1)
    {
        m_currentWeek--;
        DisplayCourseTable(m_currentWeek);
        WeekCombo.SetCurSel(m_currentWeek); // 更新组合框选择
    }
    else
    {
        AfxMessageBox(_T("已经是第一周"));
    }
}

// 下一周
void COURSEDLG::OnBnClickedCourseNext()
{
    if (m_currentWeek < 16)
    {
        m_currentWeek++;
        DisplayCourseTable(m_currentWeek);
        WeekCombo.SetCurSel(m_currentWeek); // 更新组合框选择
    }
    else
    {
        AfxMessageBox(_T("已经是最后一周"));
    }
}

// 设置开始日期
void COURSEDLG::OnBnClickedCourseSetting()
{
    DATESETDLG dlg;
    if (dlg.DoModal() == IDOK)  // 只有当用户点击确定时才更新
    {
        int year, month, day;
        dlg.returntime(year, month, day);

        // 验证选择的日期是否为星期日
        CTime newDate(year, month, day, 0, 0, 0);
        if (newDate.GetDayOfWeek() != 1) // 1表示星期日
        {
            AfxMessageBox(_T("请选择星期日作为学期开始日期"));
            return;
        }

        m_startDate = newDate;
        CalculateCurrentWeek();     // 重新计算当前周
        DisplayCourseTable(m_currentWeek); // 刷新课程表显示
    }
    return;
}

// 导入课程文件
void COURSEDLG::OnBnClickedCourseInput()
{
    CFileDialog dlg(TRUE, _T("txt"), NULL, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,
        _T("文本文件 (*.txt)|*.txt|所有文件 (*.*)|*.*||"), this);

    if (dlg.DoModal() == IDOK)
    {
        CString filePath = dlg.GetPathName();
        // 读取文件内容并解析
        std::ifstream file(filePath);
        if (file.is_open())
        {
            m_courses.RemoveAll();
            std::string line;

            // 跳过学号行
            std::getline(file, line);

            while (std::getline(file, line))
            {
                if (line.empty()) continue;

                // 解析课程数据
                std::vector<std::string> parts;
                std::istringstream iss(line);
                std::string part;

                while (std::getline(iss, part, '#'))
                {
                    parts.push_back(part);
                }

                if (parts.size() >= 5)
                {
                    CourseInfo course;
                    course.day = CString(parts[0].c_str());
                    course.sections = CString(parts[1].c_str());
                    course.name = CString(parts[2].c_str());
                    course.weeks = CString(parts[3].c_str());
                    course.location = CString(parts[4].c_str());
                    m_courses.Add(course);
                }
            }

            file.close();
            DisplayCourseTable(m_currentWeek);
            AfxMessageBox(_T("课程表导入成功"));
        }
        else
        {
            AfxMessageBox(_T("无法打开文件"));
        }
    }
}

// 周数选择
void COURSEDLG::OnCbnSelchangeCourseCombo()
{
    int nSel = WeekCombo.GetCurSel();
    if (nSel != CB_ERR && nSel != 0) // 排除描述文字选项
    {
        m_currentWeek = nSel;
        DisplayCourseTable(m_currentWeek);
    }
}

// 加载课程数据（根据学号过滤）
void COURSEDLG::LoadCourseData()
{
    // 清空原有课程数据
    m_courses.RemoveAll();

    // 尝试打开课程文件
    std::ifstream file(".//course.txt");
    if (!file.is_open())
    {
        AfxMessageBox(_T("无法打开课程文件 course.txt"));
        return;
    }

    std::string line;
    bool bFoundID = false;

    // 查找匹配的学号
    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        // 检查是否是学号行
        if (line.find_first_not_of("0123456789") == std::string::npos)
        {
            // 如果是数字行（学号行）
            CString strLine(line.c_str());
            if (strLine == ID) // 匹配当前用户学号
            {
                bFoundID = true;
                break;
            }
        }
    }

    // 如果没有找到匹配学号
    if (!bFoundID)
    {
        AfxMessageBox(_T("未找到该学号的课程信息"));
        file.close();
        return;
    }

    // 读取该学号下的课程信息
    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        // 遇到下一个学号行则停止读取
        if (line.find_first_not_of("0123456789") == std::string::npos)
            break;

        // 解析课程数据
        std::vector<std::string> parts;
        std::istringstream iss(line);
        std::string part;

        while (std::getline(iss, part, '#'))
        {
            parts.push_back(part);
        }

        if (parts.size() >= 5)
        {
            CourseInfo course;
            course.day = CString(parts[0].c_str());
            course.sections = CString(parts[1].c_str());
            course.name = CString(parts[2].c_str());
            course.weeks = CString(parts[3].c_str());
            course.location = CString(parts[4].c_str());
            m_courses.Add(course);
        }
    }

    file.close();
}

// 显示指定周的课程表
void COURSEDLG::DisplayCourseTable(int week)
{
    // 清空所有课程内容（保留节次列）
    for (int row = 0; row < m_courseList.GetItemCount(); row++) {
        for (int col = 1; col < 8; col++) {
            m_courseList.SetItemText(row, col, _T(""));
        }
    }

    // 填充课程内容
    for (int i = 0; i < m_courses.GetSize(); i++) {
        CourseInfo& course = m_courses[i];

        // 检查是否在当前周
        if (!IsCourseInWeek(course, week)) continue;

        // 解析星期几
        int dayIndex = GetDayIndex(course.day);
        if (dayIndex < 1 || dayIndex > 7) continue;

        // 填充课程信息
        CString info = course.name + _T(" ") + course.location;
        CStringArray sectionArray;
        SplitString(course.sections, ' ', sectionArray);

        for (int s = 0; s < sectionArray.GetSize(); s++) {
            CString sectionStr = sectionArray[s];

            // 遍历列表的行，匹配节次
            for (int row = 0; row < m_courseList.GetItemCount(); row++) {
                CString rowLabel = m_courseList.GetItemText(row, 0);

                // 直接比较节次字符串
                if (rowLabel == sectionStr) {
                    m_courseList.SetItemText(row, dayIndex, info);
                    break;
                }
            }
        }
    }
    // 更新标题并刷新显示
    CString title;
    title.Format(_T("本科课表 - 第%d周（当前为第%d周）"), week, currentWeek);
    SetDlgItemText(IDC_COURSE_TOPIC, title);
    m_courseList.Invalidate();
}

// 计算当前周
void COURSEDLG::CalculateCurrentWeek()
{
    CTime currentTime = CTime::GetCurrentTime();
    CTimeSpan span = currentTime - m_startDate;
    int days = span.GetDays();

    m_currentWeek = days / 7 + 1;
    currentWeek = m_currentWeek;

    if (m_currentWeek < 1) m_currentWeek = 1;
    if (m_currentWeek > 16) m_currentWeek = 16;

    // 更新组合框选择
    WeekCombo.SetCurSel(m_currentWeek);
}

// 辅助函数：分割字符串
void COURSEDLG::SplitString(const CString& str, TCHAR delim, CStringArray& arr)
{
    arr.RemoveAll();

    int start = 0;
    int end = str.Find(delim);

    while (end != -1)
    {
        arr.Add(str.Mid(start, end - start));
        start = end + 1;
        end = str.Find(delim, start);
    }

    arr.Add(str.Mid(start));
}

// 辅助函数：检查课程是否在当前周
BOOL COURSEDLG::IsCourseInWeek(const CourseInfo& course, int week)
{
    CStringArray weekArray;
    SplitString(course.weeks, ' ', weekArray);
    for (int w = 0; w < weekArray.GetSize(); w++) {
        if (_ttoi(weekArray[w]) == week) {
            return TRUE;
        }
    }
    return FALSE;
    return 0;
}

// 辅助函数：获取星期几的列索引
int COURSEDLG::GetDayIndex(const CString& day)
{
    if (day == _T("星期日")) return 1;
    if (day == _T("星期一")) return 2;
    if (day == _T("星期二")) return 3;
    if (day == _T("星期三")) return 4;
    if (day == _T("星期四")) return 5;
    if (day == _T("星期五")) return 6;
    if (day == _T("星期六")) return 7;
    return 0;
}

void COURSEDLG::getInf()
{
    // 假设通过某种方式获取类A的实例指针（如通过父窗口）
    CSmartLuoJia20Dlg* pDialogA = (CSmartLuoJia20Dlg*)GetParent();// 根据实际关系调整
    if (pDialogA)
    {
        ID = pDialogA->CurrentInf[0]; // 学号
    }
}

void COURSEDLG::OnBnClickedCourseBack()
{
    // TODO: 在此添加控件通知处理程序代码
    EndDialog(IDOK);
    MENU2Dlg newDialog;
    newDialog.DoModal();
}
