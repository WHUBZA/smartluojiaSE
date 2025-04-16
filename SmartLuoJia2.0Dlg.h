
// SmartLuoJia2.0Dlg.h: 头文件
#pragma once


// CSmartLuoJia20Dlg 对话框
class CSmartLuoJia20Dlg : public CDialogEx
{
// 构造
public:
	CSmartLuoJia20Dlg(CWnd* pParent = nullptr);	// 标准构造函数
	virtual ~CSmartLuoJia20Dlg();  // 声明析构函数
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SMARTLUOJIA20_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()

	// （可选）自定义字体
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CFont m_font;  

	// 定义背景
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CBrush m_bgBrush; // 背景画刷



public:
	//分别为密码，学号输入编辑控件的对应函数
	afx_msg void OnEnChangeStupassword();
	afx_msg void OnEnChangeStuid();

	// 实现输入控件默认显示文字
	CEdit EditSUTID;
	CEdit EditSUTPASSWORD;

	// 身份文件信息
	vector<UserInf>IDENTITY;

	// 当前读到的信息
	CString CurrentInf[3];

	CColorButton LoginButton;

	// 定义字体
	CFont FontCommon;  // 公共字体
	COLORREF TextColor1 = RGB(255, 255, 255);  // 白色

	afx_msg void OnBnClickedLogin();
};
