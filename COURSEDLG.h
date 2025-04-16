#pragma once
#include "afxdialogex.h"
#include "CColorButton2.h"

// 添加日期选择对话框
#include "DATESETDLG.h"

// COURSEDLG 对话框
class COURSEDLG : public CDialogEx
{
    DECLARE_DYNAMIC(COURSEDLG)

public:
    COURSEDLG(CWnd* pParent = nullptr);   // 标准构造函数
    virtual ~COURSEDLG();

    // 对话框数据
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_COURSE };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
    DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
    // 定义背景
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    CBrush m_bgBrush; // 背景画刷

    // 定义字体
    CFont FontCommon;  // 公共字体
    CFont FontGrid;    // 课程表格字体
    COLORREF TextColor1 = RGB(255, 255, 255);  // 白色
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

    // 图标
    HICON m_hIcon;
    afx_msg void OnPaint();

    // 按钮
    afx_msg void OnBnClickedCourseLast();
    afx_msg void OnBnClickedCourseNext();
    afx_msg void OnBnClickedCourseSetting();
    afx_msg void OnBnClickedCourseInput();
    CColorButton2 LastButton;
    CColorButton2 NextButton;
    CColorButton2 SettingButton;
    CColorButton2 InputButton;
    afx_msg void OnCbnSelchangeCourseCombo();
    CComboBox WeekCombo;

    // 获取用户学号
    CString ID;
    void getInf();

    // 课程表相关
private:
    void LoadCourseData();                     // 加载课程数据
    void DisplayCourseTable(int week);         // 显示指定周的课程表
    void CalculateCurrentWeek();               // 计算当前周


    // 课程数据结构
    struct CourseInfo {
        CString day;           // 星期几
        CString sections;      // 节次
        CString name;          // 课程名
        CString weeks;         // 周数
        CString location;     // 地点
    };

    CArray<CourseInfo> m_courses;  // 所有课程数据
    CTime m_startDate;             // 学期开始日期(第一个星期日)
    int m_currentWeek;             // 当前周(1-16)
    int currentWeek;
    CListCtrl m_courseList;        // 课程表列表控件

    void SplitString(const CString& str, TCHAR delim, CStringArray& arr);
    BOOL IsCourseInWeek(const CourseInfo& course, int week);
    int GetDayIndex(const CString& day);
   
public:
    CColorButton2 BackButton;
    afx_msg void OnBnClickedCourseBack();
};