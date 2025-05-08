#pragma once
#include "afxdialogex.h"


// LIBRARYSELECTDlg 对话框

class LIBRARYSELECTDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LIBRARYSELECTDlg)

public:
	LIBRARYSELECTDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LIBRARYSELECTDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIBRARYSELECT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	HICON m_hIcon;// 字体相关
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();

	// 定义背景
	CBrush m_bgBrush; // 背景画刷

	// 定义字体
	CFont FontCommon;  // 公共字体
	COLORREF TextColor1 = RGB(255, 255, 255);  // 白色

	// 用户信息
	CString ID;
	void getInf();

	afx_msg void OnBnClickedLibraryselectRecordbutton();
	afx_msg void OnBnClickedLibraryselectChangebutton();
	afx_msg void OnBnClickedLibraryselectReturnbutton();
	CColorButton Libary1Button;
	CColorButton Library2Button;
	CColorButton Library3Button;
	afx_msg void OnBnClickedLibrary1Button();
	afx_msg void OnBnClickedLibrary2Button();
	afx_msg void OnBnClickedLibrary3Button();
};
