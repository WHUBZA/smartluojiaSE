#pragma once
#include "afxdialogex.h"


// LIBRARY2Dlg 对话框

class LIBRARY2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(LIBRARY2Dlg)

public:
	LIBRARY2Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LIBRARY2Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIBRARY2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	HICON m_hIcon;// 字体相关
	std::string name = "2楼中厅沙发区";
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
	CButtonSTL1 L2B001;

	CButtonSTL1 L2B002;

	CButtonSTL1 L2B003;

	CButtonSTL1 L2B004;

	CButtonSTL1 L2B005;

	CButtonSTL1 L2B006;

	CButtonSTL1 L2B007;

	CButtonSTL1 L2B008;

	CButtonSTL1 L2B009;

	CButtonSTL1 L2B010;

	CButtonSTL1 L2B011;

	CButtonSTL1 L2B012;

	CButtonSTL1 L2B013;

	CButtonSTL1 L2B014;

	CButtonSTL1 L2B015;

	CButtonSTL1 L2B016;

	CButtonSTL1 L2B017;

	CButtonSTL1 L2B018;

	CButtonSTL1 L2B019;

	CButtonSTL1 L2B020;

	CButtonSTL1 L2B021;

	CButtonSTL1 L2B022;

	CButtonSTL1 L2B023;

	CButtonSTL1 L2B024;

	CButtonSTL1 L2B025;

	CButtonSTL1 L2B026;

	CButtonSTL1 L2B027;

	CButtonSTL1 L2B028;

	CButtonSTL1 L2B029;

	CButtonSTL1 L2B030;

	CButtonSTL1 L2B031;

	CButtonSTL1 L2B032;

	CButtonSTL1 L2B033;

	CButtonSTL1 L2B034;

	CButtonSTL1 L2B035;

	CButtonSTL1 L2B036;
	afx_msg void OnBnClickedLibrary2Return();
	afx_msg void OnBnClickedLibrary2Refresh();
};
