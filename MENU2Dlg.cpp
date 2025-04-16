// MENU2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "SmartLuoJia2.0.h"
#include "afxdialogex.h"
#include "MENU2Dlg.h"



// MENU2Dlg 对话框

IMPLEMENT_DYNAMIC(MENU2Dlg, CDialogEx)

MENU2Dlg::MENU2Dlg(CWnd* pParent  /*nullptr*/)
	: CDialogEx(IDD_MENU2, pParent)
{
    
}

MENU2Dlg::~MENU2Dlg()
{
	
}

void MENU2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(MENU2Dlg, CDialogEx)
	ON_WM_QUERYDRAGICON()// 字体相关
	ON_WM_ERASEBKGND() // 背景相关
	ON_WM_CTLCOLOR() // 字体设置相关
	ON_WM_PAINT() // 图片控件相关
	ON_STN_CLICKED(IDC_STATICTOPIC, &MENU2Dlg::OnStnClickedStatictopic)
	ON_BN_CLICKED(IDC_COURSEBUTTON, &MENU2Dlg::OnBnClickedCoursebutton)
	ON_BN_CLICKED(IDC_LIBRARYBUTTON, &MENU2Dlg::OnBnClickedLibrarybutton)
	ON_BN_CLICKED(IDC_GRADEBUTTON, &MENU2Dlg::OnBnClickedGradebutton)
END_MESSAGE_MAP()

BOOL MENU2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 初始化背景画刷
	m_bgBrush.CreateSolidBrush(RGB(39, 160, 134)); // 绿色背景

	// 初始化字体
	FontCommon.CreateFont(
		35, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, _T("微软雅黑"));

	// 定义按钮图标
	   // 关联按钮控件
	m_btnCourse.SubclassDlgItem(IDC_COURSEBUTTON, this);
	m_btnGrade.SubclassDlgItem(IDC_GRADEBUTTON, this);
	m_btnLibrary.SubclassDlgItem(IDC_LIBRARYBUTTON, this);

	// 加载图标
	if (m_imgCourse.Load(_T(".//res//course.ico")) == S_OK)
	{
		m_btnCourse.SetIcon(m_imgCourse);
	}

	if (m_imgGrade.Load(_T(".//res//grade.ico")) == S_OK)
	{
		m_btnGrade.SetIcon(m_imgGrade);
	}

	if (m_imgLibrary.Load(_T(".//res//library.ico")) == S_OK)
	{
		m_btnLibrary.SetIcon(m_imgLibrary);
	}

	// 设置按钮点击特效
	m_btnCourse.SetFlat(TRUE);
	m_btnGrade.SetFlat(TRUE);
	m_btnLibrary.SetFlat(TRUE);

	m_btnCourse.SetDrawCaption(FALSE);
	m_btnGrade.SetDrawCaption(FALSE);
	m_btnLibrary.SetDrawCaption(FALSE);


	// 获取用户姓名
	GetName();
	SetDlgItemText(IDC_USERNAME, INF+ _T("同学，你好！"));
	return TRUE;
}

void MENU2Dlg::OnPaint()
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
		// 绘制白框图
		{
			CImage imgBackground;
			if (SUCCEEDED(imgBackground.Load(L".\\res\\bitmap1.bmp")))
			{
				CRect rect;
				GetDlgItem(IDC_BACKGRUOND3)->GetWindowRect(&rect);
				ScreenToClient(&rect);
				dc.SetStretchBltMode(HALFTONE);
				imgBackground.Draw(dc.m_hDC, rect);
			}
		} // imgBackground自动释放
	}
}

HCURSOR MENU2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL MENU2Dlg::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	pDC->FillRect(&rect, &m_bgBrush); // 填充背景色
	return TRUE; // 阻止默认背景绘制
	return 0;
}

HBRUSH MENU2Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	UINT nID = pWnd->GetDlgCtrlID();

	// 针对特定静态文本设置样式
	if (nID == IDC_USERNAME || nID == IDC_MYAPPLICATION)
	{
		pDC->SetTextColor(TextColor1);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SelectObject(&FontCommon);
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	return CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
}




// MENU2Dlg 消息处理程序


void MENU2Dlg::OnStnClickedStatictopic()
{
	// TODO: 在此添加控件通知处理程序代码
}

void MENU2Dlg::GetName()
{
	// 假设通过某种方式获取类A的实例指针（如通过父窗口）
	CSmartLuoJia20Dlg* pDialogA = (CSmartLuoJia20Dlg*)GetParent();// 根据实际关系调整

	if (pDialogA)
	{
		INF = pDialogA->CurrentInf[2]; // 姓名
	}
}






void MENU2Dlg::OnBnClickedCoursebutton()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(IDOK);
	COURSEDLG newDialog;
	newDialog.DoModal();
}


void MENU2Dlg::OnBnClickedLibrarybutton()
{
	// TODO: 在此添加控件通知处理程序代码

	
}


void MENU2Dlg::OnBnClickedGradebutton()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(IDOK);
	GRADEDLG newDialog;
	newDialog.DoModal();
}
