// GRADEDLG.cpp: 实现文件
//

#include "pch.h"
#include "SmartLuoJia2.0.h"
#include "afxdialogex.h"
#include "GRADEDLG.h"



// GRADEDLG 对话框

IMPLEMENT_DYNAMIC(GRADEDLG, CDialogEx)

GRADEDLG::GRADEDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GRADE, pParent)
	, m_nSortColumn(-1)
	, m_nSortDirection(0)
{

}

GRADEDLG::~GRADEDLG()
{

}

void GRADEDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GRADE_LIST, gradeInf);
}

BOOL GRADEDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// 获取用户名与学号
	getInf();
	SetDlgItemText(IDC_GRADENAME,  _T("姓名：")+Name);
	SetDlgItemText(IDC_GRADEID, _T("学号：") + ID);

	// 初始化字体
	FontCommon.CreateFont(
		40, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, _T("微软雅黑"));

	FontCommon2.CreateFont(
		25, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, _T("微软雅黑"));

	// 获取列表控件
	gradeInf.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	// 整行选择、网格线
	gradeInf.InsertColumn(0, _T("课程"), LVCFMT_LEFT, 100);	
	gradeInf.InsertColumn(1, _T("课程类型"), LVCFMT_LEFT, 100);	
	gradeInf.InsertColumn(2, _T("学习类型"), LVCFMT_LEFT, 100);	
	gradeInf.InsertColumn(3, _T("学分"), LVCFMT_LEFT, 100);	
	gradeInf.InsertColumn(4, _T("成绩"), LVCFMT_LEFT, 100);	
	//设置行高
	CImageList   m_l;
	m_l.Create(1, 25, TRUE | ILC_COLOR32, 1, 0);   //设置表格的高度 
	gradeInf.SetImageList(&m_l, LVSIL_SMALL);
	
	// 设置列宽
	gradeInf.SetColumnWidth(0, 150); 
	gradeInf.SetColumnWidth(1, 150);
	gradeInf.SetColumnWidth(2, 80);
	gradeInf.SetColumnWidth(3, 80);
	gradeInf.SetColumnWidth(4, 80);
	gradeInf.SetColumnWidth(5, 80);

	// 获取数据
	gradeInfList = findGradeInf(ID);

	// 填充列表
	for (int i = 0;i < gradeInfList.size();i++)
	{
		gradeInf.InsertItem(i,_T(""));
		gradeInf.SetItemText(i, 0, gradeInfList[i].strCourse);
        gradeInf.SetItemText(i, 1, gradeInfList[i].strType);
        gradeInf.SetItemText(i, 2, gradeInfList[i].strStudyType);
        gradeInf.SetItemText(i, 3, CString(std::to_wstring(gradeInfList[i].dCredit).c_str()));
        gradeInf.SetItemText(i, 4, CString(std::to_wstring(gradeInfList[i].nScore).c_str()));
	}
	// 填充列表后计算初始GPA
	CalculateGPA();
	return TRUE;
}

// 添加GPA计算函数
void GRADEDLG::CalculateGPA()
{
	double totalCredit = 0.0;
	double totalGPA = 0.0;

	for (const auto& grade : gradeInfList)
	{
		double gpa = ScoreToGPA(grade.nScore);
		totalGPA += gpa * grade.dCredit;
		totalCredit += grade.dCredit;
	}

	double averageGPA = (totalCredit > 0) ? totalGPA / totalCredit : 0.0;

	CString strGPA;
	strGPA.Format(_T("平均GPA: %.2f"), averageGPA);
	SetDlgItemText(IDC_GPA_DISPLAY, strGPA);
}

// 添加分数转GPA函数
double GRADEDLG::ScoreToGPA(int score)
{
	if (score >= 90 && score <= 100) return 4.0;
	if (score >= 85 && score <= 89) return 3.7;
	if (score >= 82 && score <= 84) return 3.3;
	if (score >= 78 && score <= 81) return 3.0;
	if (score >= 75 && score <= 77) return 2.7;
	if (score >= 72 && score <= 74) return 2.3;
	if (score >= 68 && score <= 71) return 2.0;
	if (score >= 64 && score <= 67) return 1.5;
	if (score >= 60 && score <= 63) return 1.0;
	return 0.0;
}
// 列点击排序函数
void GRADEDLG::SortGradeList()
{
	if (m_nSortDirection > 0 && m_nSortColumn >= 0)
	{
		bool bAscending = (m_nSortDirection == 2);

		std::sort(gradeInfList.begin(), gradeInfList.end(),
			[this, bAscending](const GradeInfo& a, const GradeInfo& b) {
				switch (m_nSortColumn)
				{
				case 0: // 课程
					return bAscending ? (a.strCourse < b.strCourse) : (b.strCourse < a.strCourse);
				case 1: // 课程类型
					return bAscending ? (a.strType < b.strType) : (b.strType < a.strType);
				case 2: // 学习类型
					return bAscending ? (a.strStudyType < b.strStudyType) : (b.strStudyType < a.strStudyType);
				case 3: // 学分
					return bAscending ? (a.dCredit < b.dCredit) : (b.dCredit < a.dCredit);
				case 4: // 成绩
					return bAscending ? (a.nScore < b.nScore) : (b.nScore < a.nScore);
				default:
					return false;
				}
			});
	}
}

// 获取姓名与学号
void GRADEDLG::getInf()
{
	// 假设通过某种方式获取类A的实例指针（如通过父窗口）
	CSmartLuoJia20Dlg* pDialogA = (CSmartLuoJia20Dlg*)GetParent();// 根据实际关系调整

	if (pDialogA)
	{
		Name = pDialogA->CurrentInf[2]; // 姓名
        ID = pDialogA->CurrentInf[0]; // 学号
	}
}


BEGIN_MESSAGE_MAP(GRADEDLG, CDialogEx)
ON_WM_PAINT()
ON_WM_CTLCOLOR()
ON_NOTIFY(LVN_COLUMNCLICK, IDC_GRADE_LIST, &GRADEDLG::OnColumnclickList)
ON_BN_CLICKED(IDC_GRADE_BACK, &GRADEDLG::OnBnClickedGradeBack)
END_MESSAGE_MAP()


// GRADEDLG 消息处理程序


void GRADEDLG::OnPaint()
{
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
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
		// h
		{
			CImage imgLogo;
			if (SUCCEEDED(imgLogo.Load(L".\\res\\bitmap1.bmp")))
			{
				CRect rect;
				GetDlgItem(IDC_GRADEBACKGROUND)->GetWindowRect(&rect);
				ScreenToClient(&rect);
				dc.SetStretchBltMode(HALFTONE);
				imgLogo.Draw(dc.m_hDC, rect);
			}
		} // imgLogo自动释放


		// 绘制校徽
		{
			CImage imgLogo;
			if (SUCCEEDED(imgLogo.Load(L".\\res\\1.2.2-单色校徽.bmp")))
			{
				CRect rect;
				GetDlgItem(IDC_BADGE)->GetWindowRect(&rect);
				ScreenToClient(&rect);
				dc.SetStretchBltMode(HALFTONE);
				imgLogo.Draw(dc.m_hDC, rect);
			}
		} // imgLogo自动释放
	

		CDialogEx::OnPaint();
	}
}





HBRUSH GRADEDLG::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{

	// TODO:  在此更改 DC 的任何特性
	UINT nID = pWnd->GetDlgCtrlID();

	// 针对特定静态文本设置样式
	if (nID == IDC_GRADETOPIC)
	{
		pDC->SetTextColor(TextColor1);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SelectObject(&FontCommon);
	}
	if (nID == IDC_GRADENAME)
	{
		pDC->SetTextColor(TextColor1);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SelectObject(&FontCommon2);
	}
	if (nID == IDC_GRADEID)
	{
		pDC->SetTextColor(TextColor1);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SelectObject(&FontCommon2);
	}
	return (HBRUSH)GetStockObject(NULL_BRUSH);
	return CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
}

vector<GradeInfo> GRADEDLG::findGradeInf(CString stuID)
{
	vector<GradeInfo> curr;
	string filename = ".\\grade.txt";
    ifstream file(filename,ios::in);
	string line;
	while (std::getline(file, line))
	{
		if (line == CStringA(ID).GetString())
		{
			break;
		}
	}
    while (std::getline(file, line)&&line!="#")
	{
		GradeInfo temp2;
		stringstream ss(line);
		string temp;
		for (int i = 0;i < 5;i++)
		{
			ss >> temp;
			switch(i)
			{
			case 0:
				temp2.strCourse = temp.c_str();
				break;
            case 1:
				temp2.strType=temp.c_str();
				break;
			case 2:
				temp2.strStudyType = temp.c_str();
				break;
			case 3:
				temp2.dCredit = stoi(temp);
				break;
			case 4:
                temp2.nScore = stoi(temp);
				break;
			}
		}
		curr.push_back(temp2);
	}
	return curr;
}

// 添加列点击事件处理
void GRADEDLG::OnColumnclickList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	int nColumn = pNMLV->iSubItem;

	// 如果点击的是同一列，改变排序方向
	if (m_nSortColumn == nColumn)
	{
		m_nSortDirection = (m_nSortDirection + 1) % 3;
	}
	else
	{
		m_nSortColumn = nColumn;
		m_nSortDirection = 1; // 默认第一次点击降序
	}

	// 执行排序
	if (m_nSortDirection > 0)
	{
		SortGradeList();
	}
	else
	{
		// 恢复默认顺序
		gradeInfList = findGradeInf(ID);
	}

	// 刷新列表显示
	gradeInf.DeleteAllItems();
	for (int i = 0; i < gradeInfList.size(); i++)
	{
		gradeInf.InsertItem(i, _T(""));
		gradeInf.SetItemText(i, 0, gradeInfList[i].strCourse);
		gradeInf.SetItemText(i, 1, gradeInfList[i].strType);
		gradeInf.SetItemText(i, 2, gradeInfList[i].strStudyType);

		CString strCredit;
		strCredit.Format(_T("%.1f"), gradeInfList[i].dCredit);
		gradeInf.SetItemText(i, 3, strCredit);

		CString strScore;
		strScore.Format(_T("%d"), gradeInfList[i].nScore);
		gradeInf.SetItemText(i, 4, strScore);
	}

	// 重新计算GPA
	CalculateGPA();

	*pResult = 0;
}




void GRADEDLG::OnBnClickedGradeBack()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(IDOK);
	MENU2Dlg newDialog;
	newDialog.DoModal();
}
