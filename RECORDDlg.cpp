// RECORDDlg.cpp: 实现文件
//

#include "pch.h"
#include "SmartLuoJia2.0.h"
#include "afxdialogex.h"
#include "RECORDDlg.h"


// RECORDDlg 对话框

IMPLEMENT_DYNAMIC(RECORDDlg, CDialogEx)

RECORDDlg::RECORDDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RECORD, pParent)
{

}

RECORDDlg::~RECORDDlg()
{
}

void RECORDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RECORD_LIST, recordList);
}


BEGIN_MESSAGE_MAP(RECORDDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// RECORDDlg 消息处理程序


BOOL RECORDDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	// 获取信息
	getInf();

	// 初始化背景画刷
	m_bgBrush.CreateSolidBrush(RGB(39, 160, 134)); // 绿色背景

	// 初始化字体
	FontCommon.CreateFont(
		35, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, _T("微软雅黑"));

	// 初始化列表控件
	InitRecordList();

	// 加载预约记录
	LoadReservationRecords();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void RECORDDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
}


BOOL RECORDDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	GetClientRect(&rect);
	pDC->FillRect(&rect, &m_bgBrush); // 填充背景色
	return TRUE; // 阻止默认背景绘制
}


HBRUSH RECORDDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	UINT nID = pWnd->GetDlgCtrlID();
	if (nID == IDC_RECORD_TOPIC)
	{
		pDC->SetTextColor(TextColor1);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SelectObject(&FontCommon);
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

void RECORDDlg::InitRecordList()
{
	// 设置列表控件样式
	recordList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 添加列
	recordList.InsertColumn(0, _T("学号"), LVCFMT_LEFT, 100);
	recordList.InsertColumn(1, _T("区域"), LVCFMT_LEFT, 150);
	recordList.InsertColumn(2, _T("序号"), LVCFMT_LEFT, 60);
	recordList.InsertColumn(3, _T("月份"), LVCFMT_LEFT, 60);
	recordList.InsertColumn(4, _T("日期"), LVCFMT_LEFT, 60);
	recordList.InsertColumn(5, _T("起始时间"), LVCFMT_LEFT, 100);
	recordList.InsertColumn(6, _T("结束时间"), LVCFMT_LEFT, 100);
}

void RECORDDlg::LoadReservationRecords()
{
	// 清空列表
	recordList.DeleteAllItems();

	// 读取my_record.txt文件
	std::ifstream recordFile(".//library_inf//my_record.txt");
	if (!recordFile.is_open()) {
		MessageBox(_T("无法打开预约记录文件"), _T("错误"), MB_OK | MB_ICONERROR);
		return;
	}

	std::string line;
	std::string currentArea;

	while (std::getline(recordFile, line)) 
	{
		if (line.empty()) continue;

		if (line == "#") {
			// 新记录开始，下一行是区域名
			std::getline(recordFile, currentArea);
			continue;
		}

		// 解析记录行: 学号 座位号 月份 日期 起始时间 结束时间
		std::istringstream iss(line);
		std::string recordStudentID;
		std::string seat;
		int month, day;
		std::string startTime, endTime;

		if (iss >> recordStudentID >> seat >> month >> day >> startTime >> endTime) {
			// 只显示当前学生的记录
			if (recordStudentID == std::string(CT2A(ID.GetString())))
			{
				int nIndex = recordList.InsertItem(0, ID); // 插入新行

				// 设置各列数据
				recordList.SetItemText(nIndex, 1, CString(currentArea.c_str()));
				recordList.SetItemText(nIndex, 2, CString(seat.c_str()));
				recordList.SetItemText(nIndex, 3, CString(std::to_string(month).c_str()));
				recordList.SetItemText(nIndex, 4, CString(std::to_string(day).c_str()));
				recordList.SetItemText(nIndex, 5, CString(startTime.c_str()));
				recordList.SetItemText(nIndex, 6, CString(endTime.c_str()));
			}
		}
	}
	recordFile.close();
}

void RECORDDlg::getInf()
{
	// 假设通过某种方式获取类A的实例指针（如通过父窗口）
	LIBRARY1Dlg* pDialogA = (LIBRARY1Dlg*)GetParent();// 根据实际关系调整

	if (pDialogA)
	{
		this->ID = pDialogA->ID; // 学号
	}
}



