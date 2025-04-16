#pragma once
#include "afxdialogex.h"

// 课程信息结构体
struct GradeInfo {
	CString strCourse;     // 课程名称
	CString strType;       // 课程类型
	CString strStudyType;  // 学习类型
	double dCredit;        // 学分
	int nScore;            // 成绩
};

// GRADEDLG 对话框

class GRADEDLG : public CDialogEx
{
	DECLARE_DYNAMIC(GRADEDLG)

public:
	GRADEDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~GRADEDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GRADE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();  // 添加 OnInitDialog 函数声明
	DECLARE_MESSAGE_MAP()

	HICON m_hIcon;

private:
	int m_nSortColumn;       // 当前排序列
	int m_nSortDirection;    // 排序方向: 0-默认, 1-降序, 2-升序
	void CalculateGPA();     // 计算并显示GPA
	double ScoreToGPA(int score);  // 分数转GPA
	void SortGradeList();    // 排序函数


public:
	// 获取用户姓名与学号
    CString Name;
    CString ID;
	void getInf();
	afx_msg void OnPaint();

	// 定义字体
	CFont FontCommon;  // 公共字体
	CFont FontCommon2;
	COLORREF TextColor1 = RGB(0, 0, 0);  // 黑色
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	// 课程信息列表控件
	CListCtrl gradeInf;
	// 课程信息函数
	vector<GradeInfo> findGradeInf(CString stuID);
	// 课程信息
	vector<GradeInfo> gradeInfList;
	// 排序列点击事件
	afx_msg void OnColumnclickList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedGradeBack();
};
