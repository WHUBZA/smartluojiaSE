#pragma once
#include "afxdialogex.h"
#include "CButtonSTL1.h"

// LIBRARY1Dlg 对话框

class LIBRARY1Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(LIBRARY1Dlg)

public:
	LIBRARY1Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LIBRARY1Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIBRARY1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	HICON m_hIcon;// 字体相关
	std::string name = "创新学习苹果区";
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	// 用户信息
	CString ID;
	void getInf();

	// 定义背景
	CBrush m_bgBrush; // 背景画刷

	// 座位图标
	CButtonSTL1 L1B001;
	CImage L1P001;

	CButtonSTL1 L1B002;
	CImage L1P002;

	CButtonSTL1 L1B003;
	CImage L1P003;

	CButtonSTL1 L1B004;
	CImage L1P004;

	CButtonSTL1 L1B005;
	CImage L1P005;

	CButtonSTL1 L1B006;
	CImage L1P006;

	CButtonSTL1 L1B007;
	CImage L1P007;

	CButtonSTL1 L1B008;
	CImage L1P008;

	CButtonSTL1 L1B009;
	CImage L1P009;

	CButtonSTL1 L1B010;
	CImage L1P010;

	CButtonSTL1 L1B011;
	CImage L1P011;

	CButtonSTL1 L1B012;
	CImage L1P012;

	afx_msg void OnSeatClicked(UINT nID);
	void UpdateSeatIcons();
	afx_msg void OnBnClickedLibrary1Returnbutton();
	afx_msg void OnBnClickedLibrary1Refresh();
};
