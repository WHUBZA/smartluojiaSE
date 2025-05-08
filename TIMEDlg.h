#pragma once
#include "afxdialogex.h"


// TIMEDlg 对话框

class TIMEDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TIMEDlg)

public:
	TIMEDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~TIMEDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox startCombo;
	CComboBox endCombo;
	int m_seatNumber;
	std::string startTime;
	std::string endTime;
	afx_msg void OnOKButtonClicked();
	CString ID; // 添加学号成员变量
	string name;

};
