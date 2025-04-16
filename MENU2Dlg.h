#pragma once
#include "afxdialogex.h"
#include "SmartLuoJia2.0Dlg.h"
#include <atlimage.h>
#include "ButtonST.h" // 包含 CButtonST 类的头文件

// MENU2Dlg 对话框

class MENU2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(MENU2Dlg)

public:
	MENU2Dlg(CWnd* pParent = nullptr);   // 标准构造函数

	virtual ~MENU2Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MENU2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();  // 添加 OnInitDialog 函数声明
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	HICON m_hIcon;// 字体相关

	DECLARE_MESSAGE_MAP()

	// 定义背景
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CBrush m_bgBrush; // 背景画刷

	// （可选）自定义字体
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CFont m_font;

private:
	// 自定义按钮
	CButtonST m_btnCourse;
	CButtonST m_btnGrade;
	CButtonST m_btnLibrary;
	CImage m_imgCourse;
	CImage m_imgGrade;
	CImage m_imgLibrary;
	

public:
	// 定义字体
	CFont FontCommon;  // 公共字体
	COLORREF TextColor1 = RGB(255, 255, 255);  // 白色
	afx_msg void OnStnClickedStatictopic();

	// 获取用户数据
	CString INF;
	void GetName();
	

	// 三个按钮
	afx_msg void OnBnClickedCoursebutton();
	afx_msg void OnBnClickedLibrarybutton();
	afx_msg void OnBnClickedGradebutton();
};
