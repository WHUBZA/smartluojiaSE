// LIBRARY2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "SmartLuoJia2.0.h"
#include "afxdialogex.h"
#include "LIBRARY2Dlg.h"
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>



// LIBRARY2Dlg 对话框

IMPLEMENT_DYNAMIC(LIBRARY2Dlg, CDialogEx)

LIBRARY2Dlg::LIBRARY2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LIBRARY2, pParent)
{

}

LIBRARY2Dlg::~LIBRARY2Dlg()
{
}

void LIBRARY2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_L2B001, L2B001);
	DDX_Control(pDX, IDC_L2B002, L2B002);
	DDX_Control(pDX, IDC_L2B003, L2B003);
	DDX_Control(pDX, IDC_L2B004, L2B004);
	DDX_Control(pDX, IDC_L2B005, L2B005);
	DDX_Control(pDX, IDC_L2B006, L2B006);
	DDX_Control(pDX, IDC_L2B007, L2B007);
	DDX_Control(pDX, IDC_L2B008, L2B008);
	DDX_Control(pDX, IDC_L2B009, L2B009);
	DDX_Control(pDX, IDC_L2B010, L2B010);
	DDX_Control(pDX, IDC_L2B011, L2B011);
	DDX_Control(pDX, IDC_L2B012, L2B012);
	DDX_Control(pDX, IDC_L2B013, L2B013);
	DDX_Control(pDX, IDC_L2B014, L2B014);
	DDX_Control(pDX, IDC_L2B015, L2B015);
	DDX_Control(pDX, IDC_L2B016, L2B016);
	DDX_Control(pDX, IDC_L2B017, L2B017);
	DDX_Control(pDX, IDC_L2B018, L2B018);
	DDX_Control(pDX, IDC_L2B019, L2B019);
	DDX_Control(pDX, IDC_L2B020, L2B020);
	DDX_Control(pDX, IDC_L2B021, L2B021);
	DDX_Control(pDX, IDC_L2B022, L2B022);
	DDX_Control(pDX, IDC_L2B023, L2B023);
	DDX_Control(pDX, IDC_L2B024, L2B024);
	DDX_Control(pDX, IDC_L2B025, L2B025);
	DDX_Control(pDX, IDC_L2B026, L2B026);
	DDX_Control(pDX, IDC_L2B027, L2B027);
	DDX_Control(pDX, IDC_L2B028, L2B028);
	DDX_Control(pDX, IDC_L2B029, L2B029);
	DDX_Control(pDX, IDC_L2B030, L2B030);
	DDX_Control(pDX, IDC_L2B031, L2B031);
	DDX_Control(pDX, IDC_L2B032, L2B032);
	DDX_Control(pDX, IDC_L2B033, L2B033);
	DDX_Control(pDX, IDC_L2B034, L2B034);
	DDX_Control(pDX, IDC_L2B035, L2B035);
	DDX_Control(pDX, IDC_L2B036, L2B036);
}


BEGIN_MESSAGE_MAP(LIBRARY2Dlg, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()									 
	ON_COMMAND_RANGE(IDC_L2B001, IDC_L2B001, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B002, IDC_L2B002, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B003, IDC_L2B003, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B004, IDC_L2B004, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B005, IDC_L2B005, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B006, IDC_L2B006, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B007, IDC_L2B007, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B008, IDC_L2B008, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B009, IDC_L2B009, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B010, IDC_L2B010, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B011, IDC_L2B011, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B012, IDC_L2B012, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B013, IDC_L2B013, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B014, IDC_L2B014, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B015, IDC_L2B015, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B016, IDC_L2B016, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B017, IDC_L2B017, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B018, IDC_L2B018, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B019, IDC_L2B019, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B020, IDC_L2B020, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B021, IDC_L2B021, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B022, IDC_L2B022, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B023, IDC_L2B023, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B024, IDC_L2B024, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B025, IDC_L2B025, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B026, IDC_L2B026, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B027, IDC_L2B027, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B028, IDC_L2B028, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B029, IDC_L2B029, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B030, IDC_L2B030, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B031, IDC_L2B031, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B032, IDC_L2B032, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B033, IDC_L2B033, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B034, IDC_L2B034, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B035, IDC_L2B035, &LIBRARY2Dlg::OnSeatClicked)
	ON_COMMAND_RANGE(IDC_L2B036, IDC_L2B036, &LIBRARY2Dlg::OnSeatClicked)
	ON_BN_CLICKED(IDC_LIBRARY2_RETURN, &LIBRARY2Dlg::OnBnClickedLibrary2Return)
	ON_BN_CLICKED(IDC_LIBRARY2_REFRESH, &LIBRARY2Dlg::OnBnClickedLibrary2Refresh)
END_MESSAGE_MAP()


// LIBRARY2Dlg 消息处理程序


BOOL LIBRARY2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	// 获取学号
	getInf();
	// 初始化背景画刷
	m_bgBrush.CreateSolidBrush(RGB(255, 255, 255)); // 白色背景

	UpdateSeatIcons();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL LIBRARY2Dlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	GetClientRect(&rect);
	pDC->FillRect(&rect, &m_bgBrush); // 填充背景色
	return TRUE; // 阻止默认背景绘制
}


void LIBRARY2Dlg::OnPaint()
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
				GetDlgItem(IDC_LIBRARY2_TIP)->GetWindowRect(&rect);
				ScreenToClient(&rect);
				dc.SetStretchBltMode(HALFTONE);
				imgBackground.Draw(dc.m_hDC, rect);
			}
		} // imgBackground自动释放
	}
}

void LIBRARY2Dlg::getInf()
{
	// 假设通过某种方式获取类A的实例指针（如通过父窗口）
	CSmartLuoJia20Dlg* pDialogA = (CSmartLuoJia20Dlg*)GetParent();// 根据实际关系调整

	if (pDialogA)
	{
		ID = pDialogA->CurrentInf[0]; // 学号
	}
}

void LIBRARY2Dlg::OnSeatClicked(UINT nID)
{
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
			case IDC_L2B001: seatNumber = 1; break;
			case IDC_L2B002: seatNumber = 2; break;
			case IDC_L2B003: seatNumber = 3; break;
			case IDC_L2B004: seatNumber = 4; break;
			case IDC_L2B005: seatNumber = 5; break;
			case IDC_L2B006: seatNumber = 6; break;
			case IDC_L2B007: seatNumber = 7; break;
			case IDC_L2B008: seatNumber = 8; break;
			case IDC_L2B009: seatNumber = 9; break;
			case IDC_L2B010: seatNumber = 10; break;
			case IDC_L2B011: seatNumber = 11; break;
			case IDC_L2B012: seatNumber = 12; break;
			case IDC_L2B013: seatNumber = 13; break;
			case IDC_L2B014: seatNumber = 14; break;
			case IDC_L2B015: seatNumber = 15; break;
			case IDC_L2B016: seatNumber = 16; break;
			case IDC_L2B017: seatNumber = 17; break;
			case IDC_L2B018: seatNumber = 18; break;
			case IDC_L2B019: seatNumber = 19; break;
			case IDC_L2B020: seatNumber = 20; break;
			case IDC_L2B021: seatNumber = 21; break;
			case IDC_L2B022: seatNumber = 22; break;
			case IDC_L2B023: seatNumber = 23; break;
			case IDC_L2B024: seatNumber = 24; break;
			case IDC_L2B025: seatNumber = 25; break;
			case IDC_L2B026: seatNumber = 26; break;
			case IDC_L2B027: seatNumber = 27; break;
			case IDC_L2B028: seatNumber = 28; break;
			case IDC_L2B029: seatNumber = 29; break;
			case IDC_L2B030: seatNumber = 30; break;
			case IDC_L2B031: seatNumber = 31; break;
			case IDC_L2B032: seatNumber = 32; break;
			case IDC_L2B033: seatNumber = 33; break;
			case IDC_L2B034: seatNumber = 34; break;
			case IDC_L2B035: seatNumber = 35; break;
			case IDC_L2B036: seatNumber = 36; break;
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
			case IDC_L2B001: seatNumber = 1; break;
			case IDC_L2B002: seatNumber = 2; break;
			case IDC_L2B003: seatNumber = 3; break;
			case IDC_L2B004: seatNumber = 4; break;
			case IDC_L2B005: seatNumber = 5; break;
			case IDC_L2B006: seatNumber = 6; break;
			case IDC_L2B007: seatNumber = 7; break;
			case IDC_L2B008: seatNumber = 8; break;
			case IDC_L2B009: seatNumber = 9; break;
			case IDC_L2B010: seatNumber = 10; break;
			case IDC_L2B011: seatNumber = 11; break;
			case IDC_L2B012: seatNumber = 12; break;
			case IDC_L2B013: seatNumber = 13; break;
			case IDC_L2B014: seatNumber = 14; break;
			case IDC_L2B015: seatNumber = 15; break;
			case IDC_L2B016: seatNumber = 16; break;
			case IDC_L2B017: seatNumber = 17; break;
			case IDC_L2B018: seatNumber = 18; break;
			case IDC_L2B019: seatNumber = 19; break;
			case IDC_L2B020: seatNumber = 20; break;
			case IDC_L2B021: seatNumber = 21; break;
			case IDC_L2B022: seatNumber = 22; break;
			case IDC_L2B023: seatNumber = 23; break;
			case IDC_L2B024: seatNumber = 24; break;
			case IDC_L2B025: seatNumber = 25; break;
			case IDC_L2B026: seatNumber = 26; break;
			case IDC_L2B027: seatNumber = 27; break;
			case IDC_L2B028: seatNumber = 28; break;
			case IDC_L2B029: seatNumber = 29; break;
			case IDC_L2B030: seatNumber = 30; break;
			case IDC_L2B031: seatNumber = 31; break;
			case IDC_L2B032: seatNumber = 32; break;
			case IDC_L2B033: seatNumber = 33; break;
			case IDC_L2B034: seatNumber = 34; break;
			case IDC_L2B035: seatNumber = 35; break;
			case IDC_L2B036: seatNumber = 36; break;
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

void LIBRARY2Dlg::UpdateSeatIcons()
{
	std::time_t now = std::time(nullptr);
	std::tm* currentTime = std::localtime(&now);
	std::tm currentTm = *currentTime;
	currentTm.tm_sec = 0;

	for (int i = 0; i < 36; ++i)
	{
		ifstream seatsLines(".//library_inf//seats.txt", ios::in);
		CButtonSTL1* pButton = nullptr;
		switch (i)
		{
		case 0:										
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B001);
			break;									
		case 1:										
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B002);
			break;									
		case 2:										
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B003);
			break;									
		case 3:										
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B004);
			break;									
		case 4:										
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B005);
			break;									
		case 5:										
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B006);
			break;									
		case 6:										
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B007);
			break;									
		case 7:										
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B008);
			break;									
		case 8:										
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B009);
			break;									
		case 9:										
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B010);
			break;									
		case 10:									
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B011);
			break;									
		case 11:									
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B012);
			break;
		case 12:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B013);
			break;
		case 13:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B014);
			break;
		case 14:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B015);
			break;
		case 15:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B016);
			break;
		case 16:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B017);
			break;
		case 17:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B018);
			break;
		case 18:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B019);
			break;
		case 19:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B020);
			break;
		case 20:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B021);
			break;
		case 21:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B022);
			break;
		case 22:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B023);
			break;
		case 23:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B024);
			break;
		case 24:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B025);
			break;
		case 25:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B026);
			break;
		case 26:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B027);
			break;
		case 27:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B028);
			break;
		case 28:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B029);
			break;
		case 29:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B030);
			break;
		case 30:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B031);
			break;
		case 31:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B032);
			break;
		case 32:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B033);
			break;
		case 33:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B034);
			break;
		case 34:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B035);
			break;
		case 35:
			pButton = (CButtonSTL1*)GetDlgItem(IDC_L2B036);
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
				while (getline(seatsLines, line) && line != "#")

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
		normalIconPath.Format(_T(".//res//library2//%s.png"), CString(seatNumberStr.c_str()));
		grayIconPath.Format(_T(".//res//library2//g%s.png"), CString(seatNumberStr.c_str()));

		if (isOccupied) {
			if (pButton) {
				CImage grayImage;
				if (grayImage.Load(grayIconPath) == S_OK) {
					pButton->setPicture(48,48);
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
					pButton->setPicture(48, 48);
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





void LIBRARY2Dlg::OnBnClickedLibrary2Return()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(IDOK);
	LIBRARYSELECTDlg newDialog;
	newDialog.DoModal();
}


void LIBRARY2Dlg::OnBnClickedLibrary2Refresh()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateSeatIcons();
}
