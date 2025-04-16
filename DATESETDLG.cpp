// DATESETDLG.cpp: 实现文件
//

#include "pch.h"
#include "SmartLuoJia2.0.h"
#include "afxdialogex.h"
#include "DATESETDLG.h"


// DATESETDLG 对话框

IMPLEMENT_DYNAMIC(DATESETDLG, CDialogEx)

DATESETDLG::DATESETDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DATESET, pParent)
{

}

DATESETDLG::~DATESETDLG()
{
}

void DATESETDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DATESETDLG, CDialogEx)
	ON_BN_CLICKED(IDOK, &DATESETDLG::OnBnClickedOk)
END_MESSAGE_MAP()


// DATESETDLG 消息处理程序


BOOL DATESETDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	// 控制输入控件默认显示
	// 获取编辑框控件
	EditYEAR.SubclassDlgItem(IDC_DATESET_YEAR, this);
	EditYEAR.SetCueBanner(L"请输入年份", TRUE);

	EditMONTH.SubclassDlgItem(IDC_DATESET_MONTH, this);
	EditMONTH.SetCueBanner(L"请输入月份", TRUE);

	EditDAY.SubclassDlgItem(IDC_DATESET_DAY, this);
	EditDAY.SetCueBanner(L"请输入日期", TRUE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void DATESETDLG::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	 // 实时获取输入框内容
	GetDlgItemText(IDC_DATESET_YEAR, year);
	GetDlgItemText(IDC_DATESET_MONTH, month);
	GetDlgItemText(IDC_DATESET_DAY, day);
	CDialogEx::OnOK();
	
}

void DATESETDLG::returntime(int& a, int& b, int& c)
{
	a=_ttoi(year);
    b=_ttoi(month);
    c=_ttoi(day);
	return;
}
