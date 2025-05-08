#pragma once
#include "afxdialogex.h"


// RECORDDlg 对话框

class RECORDDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RECORDDlg)

public:
	RECORDDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~RECORDDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RECORD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	HICON m_hIcon;// 字体相关
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	// 初始化列表控件
	void InitRecordList();

	// 加载预约记录
	void LoadReservationRecords();

	// 定义背景
	CBrush m_bgBrush; // 背景画刷


	// 定义字体
	CFont FontCommon;  // 公共字体
	COLORREF TextColor1 = RGB(255, 255, 255);  // 白色

	CString ID;
    void getInf();
	CListCtrl recordList;
	
};
