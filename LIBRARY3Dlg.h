#pragma once
#include "afxdialogex.h"


// LIBRARY3Dlg 对话框

class LIBRARY3Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(LIBRARY3Dlg)

public:
	LIBRARY3Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LIBRARY3Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIBRARY3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	HICON m_hIcon;// 字体相关
	std::string name = "409展览区";
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();

	// 定义背景
	CBrush m_bgBrush; // 背景画刷

	// 用户信息
	CString ID;
	void getInf();

	// 功能函数
	afx_msg void OnSeatClicked(UINT nID);
	void UpdateSeatIcons();

	// 座位图标
	CButtonSTL1 L3B001;
	CButtonSTL1 L3B002;
	CButtonSTL1 L3B003;
	CButtonSTL1 L3B004;
	CButtonSTL1 L3B005;
	CButtonSTL1 L3B006;
	CButtonSTL1 L3B007;
	CButtonSTL1 L3B008;
	CButtonSTL1 L3B009;
	CButtonSTL1 L3B010;
	CButtonSTL1 L3B011;
	CButtonSTL1 L3B012;
	CButtonSTL1 L3B013;
	CButtonSTL1 L3B014;
	CButtonSTL1 L3B015;
	CButtonSTL1 L3B016;
	CButtonSTL1 L3B017;
	CButtonSTL1 L3B018;
	CButtonSTL1 L3B019;
	CButtonSTL1 L3B020;
	CButtonSTL1 L3B021;
	CButtonSTL1 L3B022;
	CButtonSTL1 L3B023;
	CButtonSTL1 L3B024;
	CButtonSTL1 L3B025;
	CButtonSTL1 L3B026;
	CButtonSTL1 L3B027;
	CButtonSTL1 L3B028;
	CButtonSTL1 L3B029;
	CButtonSTL1 L3B030;
	CButtonSTL1 L3B031;
	CButtonSTL1 L3B032;
	afx_msg void OnBnClickedLibrary3Returnbutton();
	afx_msg void OnBnClickedLibrary3Refrsehbutton();
};
