// LIBRARY1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "SmartLuoJia2.0.h"
#include "afxdialogex.h"
#include "LIBRARY1Dlg.h"
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>

// 通用文件读取函数
std::vector<std::string> readFile(const std::string& filePath) {
	std::vector<std::string> lines;
	std::ifstream file(filePath);
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			lines.push_back(line);
		}
		file.close();
	}
	return lines;
}

// 通用文件写入函数
void writeFile(const std::string& filePath, const std::vector<std::string>& lines) {
	std::ofstream file(filePath);
	if (file.is_open()) {
		for (const auto& line : lines) {
			file << line << std::endl;
		}
		file.close();
	}
}




// LIBRARY1Dlg 对话框

IMPLEMENT_DYNAMIC(LIBRARY1Dlg, CDialogEx)

LIBRARY1Dlg::LIBRARY1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LIBRARY1, pParent)
{

}

LIBRARY1Dlg::~LIBRARY1Dlg()
{
}

void LIBRARY1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_L1B001, L1B001);
	DDX_Control(pDX, IDC_L1B002, L1B002);
	DDX_Control(pDX, IDC_L1B003, L1B003);
	DDX_Control(pDX, IDC_L1B004, L1B004);
	DDX_Control(pDX, IDC_L1B005, L1B005);
	DDX_Control(pDX, IDC_L1B006, L1B006);
	DDX_Control(pDX, IDC_L1B007, L1B007);
	DDX_Control(pDX, IDC_L1B008, L1B008);
	DDX_Control(pDX, IDC_L1B009, L1B009);
	DDX_Control(pDX, IDC_L1B010, L1B010);
	DDX_Control(pDX, IDC_L1B011, L1B011);
	DDX_Control(pDX, IDC_L1B012, L1B012);
}


BEGIN_MESSAGE_MAP(LIBRARY1Dlg, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_COMMAND_RANGE(IDC_L1B001, IDC_L1B001, &LIBRARY1Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L1B002, IDC_L1B002, &LIBRARY1Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L1B003, IDC_L1B003, &LIBRARY1Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L1B004, IDC_L1B004, &LIBRARY1Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L1B005, IDC_L1B005, &LIBRARY1Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L1B006, IDC_L1B006, &LIBRARY1Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L1B007, IDC_L1B007, &LIBRARY1Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L1B008, IDC_L1B008, &LIBRARY1Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L1B009, IDC_L1B009, &LIBRARY1Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L1B010, IDC_L1B010, &LIBRARY1Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L1B011, IDC_L1B011, &LIBRARY1Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L1B012, IDC_L1B012, &LIBRARY1Dlg::OnSeatClicked)
	ON_BN_CLICKED(IDC_LIBRARY1_RETURNBUTTON, &LIBRARY1Dlg::OnBnClickedLibrary1Returnbutton)
	ON_BN_CLICKED(IDC_LIBRARY1_REFRESH, &LIBRARY1Dlg::OnBnClickedLibrary1Refresh)
END_MESSAGE_MAP()


// LIBRARY1Dlg 消息处理程序


BOOL LIBRARY1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	// 获取学号
	getInf();
	// 初始化背景画刷
	m_bgBrush.CreateSolidBrush(RGB(255, 255, 255)); // 白色背景
	
	// 更新座位图标
	UpdateSeatIcons();


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL LIBRARY1Dlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	GetClientRect(&rect);
	pDC->FillRect(&rect, &m_bgBrush); // 填充背景色
	return TRUE; // 阻止默认背景绘制
}


void LIBRARY1Dlg::OnPaint()
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
		// 绘制提示图标
		{
			CImage imgBackground;
			if (SUCCEEDED(imgBackground.Load(L".\\res\\LIBRARYTIP.png")))
			{
				CRect rect;
				GetDlgItem(IDC_LIBRARY1_TIP)->GetWindowRect(&rect);
				ScreenToClient(&rect);
				dc.SetStretchBltMode(HALFTONE);
				imgBackground.Draw(dc.m_hDC, rect);
			}
		} // imgBackground自动释放
	}
}

void LIBRARY1Dlg::getInf()
{
	// 假设通过某种方式获取类A的实例指针（如通过父窗口）
	CSmartLuoJia20Dlg* pDialogA = (CSmartLuoJia20Dlg*)GetParent();// 根据实际关系调整

	if (pDialogA)
	{
		ID = pDialogA->CurrentInf[0]; // 学号
	}
}

void LIBRARY1Dlg::OnSeatClicked(UINT nID) {
	
	CButtonSTL1* pButton = (CButtonSTL1*)GetDlgItem(nID);
	if (pButton) {
		if (pButton->flag) {
			// 检查用户今日是否已有预约记录
			std::ifstream recordFile(".//library_inf//my_record.txt");
			if (recordFile.is_open()) {
				std::string line;
				std::time_t now = std::time(nullptr);
				std::tm* currentTime = std::localtime(&now);
				int currentDay = currentTime->tm_mday;
				int currentMonth = currentTime->tm_mon + 1;

				bool hasRecordToday = false;
				std::string studentId = CT2A(ID); // 将CString ID转换为std::string

				while (std::getline(recordFile, line)) {
					if (line == "#") {
						// 找到一个新的预约记录块
						std::getline(recordFile, line); // 读取区域名
						std::getline(recordFile, line); // 读取预约记录

						std::istringstream iss(line);
						std::string recordStudentId;
						int seat, month, day;
						std::string startTime, endTime;

						if (iss >> recordStudentId >> seat >> month >> day >> startTime >> endTime) {
							// 检查学号和日期是否匹配
							if (recordStudentId == studentId && month == currentMonth && day == currentDay) {
								hasRecordToday = true;
								break;
							}
						}
					}
				}
				recordFile.close();

				if (hasRecordToday) {
					MessageBox(_T("今日预约次数已达上限（一人一天一次）"), _T("提示"), MB_OK | MB_ICONINFORMATION);
					UpdateSeatIcons();
					return;
				}
			}
			else {
				MessageBox(_T("无法读取预约记录文件"), _T("错误"), MB_OK | MB_ICONERROR);
				return;
			}

			// 获取座位号
			int seatNumber = 0;
			switch (nID) {
			case IDC_L1B001: seatNumber = 1; break;
			case IDC_L1B002: seatNumber = 2; break;
			case IDC_L1B003: seatNumber = 3; break;
			case IDC_L1B004: seatNumber = 4; break;
			case IDC_L1B005: seatNumber = 5; break;
			case IDC_L1B006: seatNumber = 6; break;
			case IDC_L1B007: seatNumber = 7; break;
			case IDC_L1B008: seatNumber = 8; break;
			case IDC_L1B009: seatNumber = 9; break;
			case IDC_L1B010: seatNumber = 10; break;
			case IDC_L1B011: seatNumber = 11; break;
			case IDC_L1B012: seatNumber = 12; break;
			}

			// 打开时间选择对话框
			TIMEDlg timeDlg;
			timeDlg.m_seatNumber = seatNumber;
			timeDlg.ID = this->ID; // 传递学号到时间对话框
			timeDlg.name = (this->name);
			if (timeDlg.DoModal() == IDOK) {
				// 预约成功后更新座位图标
				UpdateSeatIcons();
			}
		}
		else {
			// 座位不可用，给出提示信息
			MessageBox(_T("该座位已被占用，请选择其他座位！"), _T("提示"), MB_OK | MB_ICONINFORMATION);
			UpdateSeatIcons();
		}
	}
}

// 更新座位图标
void LIBRARY1Dlg::UpdateSeatIcons() 
{
	std::time_t now = std::time(nullptr);
	std::tm* currentTime = std::localtime(&now);
	std::tm currentTm = *currentTime;
	currentTm.tm_sec = 0;

	for (int i = 0; i < 12; ++i) 
	{
		ifstream seatsLines(".//library_inf//seats.txt", ios::in);
		CButtonSTL1* pButton=nullptr;
		switch (i) 
		{
		case 0:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L1B001);
			break;
		case 1:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L1B002);
			break;
		case 2:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L1B003);
			break;
		case 3:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L1B004);
			break;
		case 4:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L1B005);
			break;
		case 5:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L1B006);
			break;
		case 6:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L1B007);
			break;
		case 7:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L1B008);
			break;
		case 8:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L1B009);
			break;
		case 9:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L1B010);
			break;
		case 10:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L1B011);
			break;
		case 11:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L1B012);
			break;
		}
		std::string seatNumberStr = std::to_string(i + 1);
		if (seatNumberStr.length() == 1) {
			seatNumberStr = "00" + seatNumberStr;
		}
		else
		{
			seatNumberStr = "0" + seatNumberStr;
		}
		bool isOccupied = false;

		std::string line;
		while (getline(seatsLines, line))
		{
			if (line == name)
			{
				while(getline(seatsLines, line)&&line!="#")
				
				{
					std::string seatNumber;
					std::tm startTm = {};
					std::tm endTm = {};
					std::string startStr, endStr;
					std::stringstream iss(line);
					iss >> seatNumber >> startStr >> endStr;
					// 解析时间字符串
					std::istringstream startIss(startStr);
					std::istringstream endIss(endStr);
					startIss >> std::get_time(&startTm, "%H:%M");
					endIss >> std::get_time(&endTm, "%H:%M");

					// 匹配区域名和座位号
					if (seatNumber == seatNumberStr) {
						if (compareTime(currentTm, endTm) && compareTime(startTm, currentTm)) {
							isOccupied = true;
							break;
						}
					}
				}
				break;
			}
		}

		CString normalIconPath;
		CString grayIconPath;
		normalIconPath.Format(_T(".//res//library1//%s.png"), CString(seatNumberStr.c_str()));
		grayIconPath.Format(_T(".//res//library1//g%s.png"), CString(seatNumberStr.c_str()));

		if (isOccupied) {
			if (pButton) {
				CImage grayImage;
				if (grayImage.Load(grayIconPath) == S_OK) {
					pButton->SetIcon(grayImage);
					pButton->SetFlat(TRUE);
					pButton->SetDrawCaption(FALSE);
					pButton->flag = false;
				}
			}
		}
		else {
			if (pButton) {
				CImage normalImage;
				if (normalImage.Load(normalIconPath) == S_OK) {
					pButton->SetIcon(normalImage);
					pButton->SetFlat(TRUE);
					pButton->SetDrawCaption(FALSE);
					pButton->flag = true;
				}
			}
		}
		seatsLines.close();
	}
}


void LIBRARY1Dlg::OnBnClickedLibrary1Returnbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(IDOK);
	LIBRARYSELECTDlg newDialog;
	newDialog.DoModal();
}


void LIBRARY1Dlg::OnBnClickedLibrary1Refresh()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateSeatIcons();
}
