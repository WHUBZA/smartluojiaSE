// LIBRARYSELECTDlg.cpp: 实现文件
//

#include "pch.h"
#include "SmartLuoJia2.0.h"
#include "afxdialogex.h"
#include "LIBRARYSELECTDlg.h"


// LIBRARYSELECTDlg 对话框

IMPLEMENT_DYNAMIC(LIBRARYSELECTDlg, CDialogEx)

LIBRARYSELECTDlg::LIBRARYSELECTDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LIBRARYSELECT, pParent)
{

}

LIBRARYSELECTDlg::~LIBRARYSELECTDlg()
{
}

void LIBRARYSELECTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIBRARY1_BUTTON, Libary1Button);
	DDX_Control(pDX, IDC_LIBRARY2_BUTTON, Library2Button);
	DDX_Control(pDX, IDC_LIBRARY3_BUTTON, Library3Button);
}


BEGIN_MESSAGE_MAP(LIBRARYSELECTDlg, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_LIBRARYSELECT_RECORDBUTTON, &LIBRARYSELECTDlg::OnBnClickedLibraryselectRecordbutton)
	ON_BN_CLICKED(IDC_LIBRARYSELECT_CHANGEBUTTON, &LIBRARYSELECTDlg::OnBnClickedLibraryselectChangebutton)
	ON_BN_CLICKED(IDC_LIBRARYSELECT_RETURNBUTTON, &LIBRARYSELECTDlg::OnBnClickedLibraryselectReturnbutton)
	ON_BN_CLICKED(IDC_LIBRARY1_BUTTON, &LIBRARYSELECTDlg::OnBnClickedLibrary1Button)
	ON_BN_CLICKED(IDC_LIBRARY2_BUTTON, &LIBRARYSELECTDlg::OnBnClickedLibrary2Button)
	ON_BN_CLICKED(IDC_LIBRARY3_BUTTON, &LIBRARYSELECTDlg::OnBnClickedLibrary3Button)
END_MESSAGE_MAP()


// LIBRARYSELECTDlg 消息处理程序


BOOL LIBRARYSELECTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	// 获取学号
	getInf();

	// 初始化背景画刷
	m_bgBrush.CreateSolidBrush(RGB(39, 160, 134)); // 绿色背景

	// 初始化字体
	FontCommon.CreateFont(
		35, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, _T("微软雅黑"));















	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


HBRUSH LIBRARYSELECTDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
		// 针对特定静态文本设置样式
	UINT nID = pWnd->GetDlgCtrlID();
	if (nID == IDC_LIBRARYSELECTTOPIC)
	{
		pDC->SetTextColor(TextColor1);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SelectObject(&FontCommon);
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


BOOL LIBRARYSELECTDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	GetClientRect(&rect);
	pDC->FillRect(&rect, &m_bgBrush); // 填充背景色
	return TRUE; // 阻止默认背景绘制
	return CDialogEx::OnEraseBkgnd(pDC);
}


void LIBRARYSELECTDlg::OnPaint()
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
				GetDlgItem(IDC_LIBRARYSELECTBACKGROUND)->GetWindowRect(&rect);
				ScreenToClient(&rect);
				dc.SetStretchBltMode(HALFTONE);
				imgBackground.Draw(dc.m_hDC, rect);
			}
		} // imgBackground自动释放
		// 绘制校徽
		{
			CImage imgLogo;
			if (SUCCEEDED(imgLogo.Load(L".\\res\\校徽.png")))
			{
				CRect rect;
				GetDlgItem(IDC_LIBRARYSELCET_BADGE)->GetWindowRect(&rect);
				ScreenToClient(&rect);
				dc.SetStretchBltMode(HALFTONE);
				imgLogo.Draw(dc.m_hDC, rect);
			}
		} // imgLogo自动释放
	}
}




void LIBRARYSELECTDlg::getInf()
{
	// 假设通过某种方式获取类A的实例指针（如通过父窗口）
	CSmartLuoJia20Dlg* pDialogA = (CSmartLuoJia20Dlg*)GetParent();// 根据实际关系调整

	if (pDialogA)
	{
		ID = pDialogA->CurrentInf[0]; // 学号
	}
}

void LIBRARYSELECTDlg::OnBnClickedLibraryselectRecordbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	RECORDDlg newDialog;
	newDialog.DoModal();
}


void LIBRARYSELECTDlg::OnBnClickedLibraryselectChangebutton()
{
	// TODO: 在此添加控件通知处理程序代码
      // 获取当前日期
    std::time_t now = std::time(nullptr);
    std::tm* currentTime = std::localtime(&now);
    int currentDay = currentTime->tm_mday;
    int currentMonth = currentTime->tm_mon + 1;

    // 转换学号为string
    std::string studentID = CT2A(ID.GetString());
    bool recordFound = false;

    // 处理seats.txt文件
    {
        std::vector<std::string> seatsLines;
        std::ifstream seatsFile(".//library_inf//seats.txt");
        if (seatsFile.is_open()) {
            std::string line;
            while (std::getline(seatsFile, line)) {
                seatsLines.push_back(line);
            }
            seatsFile.close();
        }

        // 查找并删除相关记录
        std::string currentArea;
        for (size_t i = 0; i < seatsLines.size(); ) {
            if (seatsLines[i] == "#") {
                currentArea = (i + 1 < seatsLines.size()) ? seatsLines[i + 1] : "";
                i += 2;
                continue;
            }

            std::istringstream iss(seatsLines[i]);
            int seat;
            std::string start, end;
            if (iss >> seat >> start >> end) {
                // 在my_record.txt中检查是否属于当前用户
                std::ifstream recordFile(".//library_inf//my_record.txt");
                if (recordFile.is_open()) {
                    std::string recordLine;
                    while (std::getline(recordFile, recordLine)) {
                        if (recordLine == "#") {
                            std::getline(recordFile, recordLine); // 区域名
                            std::getline(recordFile, recordLine); // 记录行

                            std::istringstream recordIss(recordLine);
                            std::string recordID;
                            int recordSeat, recordMonth, recordDay;
                            std::string recordStart, recordEnd;

                            if (recordIss >> recordID >> recordSeat >> recordMonth >> recordDay >> recordStart >> recordEnd) {
                                if (recordID == studentID &&
                                    recordSeat == seat &&
                                    recordMonth == currentMonth &&
                                    recordDay == currentDay) {
                                    // 删除seats.txt中的记录
                                    seatsLines.erase(seatsLines.begin() + i);
                                    recordFound = true;
                                    break;
                                }
                            }
                        }
                    }
                    recordFile.close();
                }
            }

            if (!recordFound) {
                i++;
            }
            else {
                recordFound = false; // 重置标志继续查找
            }
        }

        // 写回文件
        std::ofstream seatsOutFile(".//library_inf//seats.txt");
        if (seatsOutFile.is_open()) {
            for (const auto& line : seatsLines) {
                seatsOutFile << line << std::endl;
            }
            seatsOutFile.close();
        }
    }

    // 处理my_record.txt文件
    {
        std::vector<std::string> recordLines;
        std::ifstream recordFile(".//library_inf//my_record.txt");
        if (recordFile.is_open()) {
            std::string line;
            while (std::getline(recordFile, line)) {
                recordLines.push_back(line);
            }
            recordFile.close();
        }

        // 查找并删除相关记录
        for (size_t i = 0; i < recordLines.size(); ) {
            if (recordLines[i] == "#" && i + 2 < recordLines.size()) {
                std::string area = recordLines[i + 1];
                std::string record = recordLines[i + 2];

                std::istringstream iss(record);
                std::string recordID;
                int seat, month, day;
                std::string start, end;

                if (iss >> recordID >> seat >> month >> day >> start >> end) {
                    if (recordID == studentID && month == currentMonth && day == currentDay) {
                        // 删除整个记录块
                        recordLines.erase(recordLines.begin() + i, recordLines.begin() + i + 3);
                        recordFound = true;
                        continue;
                    }
                }
            }
            i++;
        }

        // 写回文件
        std::ofstream recordOutFile(".//library_inf//my_record.txt");
        if (recordOutFile.is_open()) {
            for (const auto& line : recordLines) {
                recordOutFile << line << std::endl;
            }
            recordOutFile.close();
        }
    }

    // 显示操作结果
    if (recordFound) {
        MessageBox(_T("已成功退约"), _T("提示"), MB_OK | MB_ICONINFORMATION);
    }
    else {
        MessageBox(_T("未能查询到相应记录"), _T("提示"), MB_OK | MB_ICONINFORMATION);
    }
}


void LIBRARYSELECTDlg::OnBnClickedLibraryselectReturnbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(IDOK);
	MENU2Dlg newDialog;
	newDialog.DoModal();
}


void LIBRARYSELECTDlg::OnBnClickedLibrary1Button()
{
	EndDialog(IDOK);
	LIBRARY1Dlg newDialog;
	newDialog.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void LIBRARYSELECTDlg::OnBnClickedLibrary2Button()
{
	// TODO: 在此添加控件通知处理程序代码
    EndDialog(IDOK);
    LIBRARY2Dlg newDialog;
    newDialog.DoModal();
}


void LIBRARYSELECTDlg::OnBnClickedLibrary3Button()
{
	// TODO: 在此添加控件通知处理程序代码
    EndDialog(IDOK);
    LIBRARY3Dlg newDialog;
    newDialog.DoModal();
}
