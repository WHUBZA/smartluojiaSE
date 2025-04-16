#pragma once
#include "afxdialogex.h"


// DATESETDLG 对话框

class DATESETDLG : public CDialogEx
{
	DECLARE_DYNAMIC(DATESETDLG)

public:
	DATESETDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DATESETDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DATESET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEdit EditYEAR;
	CEdit EditMONTH;
    CEdit EditDAY;
	CString year;
	CString month;
	CString day;
	afx_msg void OnBnClickedOk();
	void returntime(int& a, int& b, int& c);
};
