
// SmartLuoJia2.0Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "SmartLuoJia2.0.h"
#include "SmartLuoJia2.0Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CSmartLuoJia20Dlg 对话框



CSmartLuoJia20Dlg::CSmartLuoJia20Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SMARTLUOJIA20_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CSmartLuoJia20Dlg::~CSmartLuoJia20Dlg()
{
	// 释放背景画刷
	m_bgBrush.DeleteObject();


}

void CSmartLuoJia20Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LOGIN, LoginButton);
}
BEGIN_MESSAGE_MAP(CSmartLuoJia20Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_STUPASSWORD, &CSmartLuoJia20Dlg::OnEnChangeStupassword)
	ON_EN_CHANGE(IDC_STUID, &CSmartLuoJia20Dlg::OnEnChangeStuid)
	ON_WM_CTLCOLOR() //字体设置相关
	ON_WM_ERASEBKGND() // 背景相关
	ON_BN_CLICKED(IDC_LOGIN, &CSmartLuoJia20Dlg::OnBnClickedLogin)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CSmartLuoJia20Dlg 消息处理程序

BOOL CSmartLuoJia20Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	// 字体缩放
	
	
	// 初始化字体
	FontCommon.CreateFont(
		40, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, _T("微软雅黑"));
	
	// 初始化背景画刷
	CDialogEx::OnInitDialog();
	m_bgBrush.CreateSolidBrush(RGB(39, 160, 134)); // 绿色背景
	


	// 读取已写入的账户信息
	string filename = "identity.txt";
	ifstream inf(filename, ios::in);
	string line;
	while (getline(inf, line))
	{
		UserInf temp(line);
		IDENTITY.push_back(temp);
	}

	// 控制输入控件默认显示
	// 获取编辑框控件
	EditSUTID.SubclassDlgItem(IDC_STUID, this);
	// 设置提示文字
	EditSUTID.SetCueBanner(L"请输入学号", TRUE);
	// 获取编辑框控件
	EditSUTPASSWORD.SubclassDlgItem(IDC_STUPASSWORD, this);
	// 设置提示文字
	EditSUTPASSWORD.SetCueBanner(L"请输入密码", TRUE);






	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSmartLuoJia20Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSmartLuoJia20Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		// 绘制校徽
		{
			CImage imgLogo;
			if (SUCCEEDED(imgLogo.Load(L".\\res\\校徽.png")))
			{
				CRect rect;
				GetDlgItem(IDC_BACKGROUND2)->GetWindowRect(&rect);
				ScreenToClient(&rect);
				dc.SetStretchBltMode(HALFTONE);
				imgLogo.Draw(dc.m_hDC, rect);
			}
		} // imgLogo自动释放
		// 绘制白框图
		{
			CImage imgBackground;
			if (SUCCEEDED(imgBackground.Load(L".\\res\\bitmap1.bmp")))
			{
				CRect rect;
				GetDlgItem(IDC_BACKGRUOND1)->GetWindowRect(&rect);
				ScreenToClient(&rect);
				dc.SetStretchBltMode(HALFTONE);
				imgBackground.Draw(dc.m_hDC, rect);
			}
		} // imgBackground自动释放


		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。

//按控件ID设置字体
HCURSOR CSmartLuoJia20Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HBRUSH CSmartLuoJia20Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	UINT nID = pWnd->GetDlgCtrlID();

	// 针对特定静态文本设置样式
	if (nID == IDC_STATICTOPIC)
	{
		pDC->SetTextColor(TextColor1);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SelectObject(&FontCommon);
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	return CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
}

BOOL CSmartLuoJia20Dlg::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	pDC->FillRect(&rect, &m_bgBrush); // 填充背景色
	return TRUE; // 阻止默认背景绘制
}


void CSmartLuoJia20Dlg::OnEnChangeStupassword()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CSmartLuoJia20Dlg::OnEnChangeStuid()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}




void CSmartLuoJia20Dlg::OnBnClickedLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	 // 实时获取输入框内容
	GetDlgItemText(IDC_STUID, CurrentInf[0]);
	GetDlgItemText(IDC_STUPASSWORD, CurrentInf[1]);

	// 去除首尾空白字符
	CurrentInf[0].Trim();
	CurrentInf[1].Trim();

	for (int i = 0; i < IDENTITY.size(); i++)
	{
		if (CurrentInf[0] == IDENTITY[i].FindID().c_str() &&
			CurrentInf[1] == IDENTITY[i].FindPassword().c_str())
		{
			CurrentInf[2] = IDENTITY[i].FindName().c_str();
			EndDialog(IDOK);
			MENU2Dlg newDialog;
			newDialog.DoModal();
			return;
		}
	}
	AfxMessageBox(_T("账号或密码输入错误！"));
}




void CSmartLuoJia20Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	
}





