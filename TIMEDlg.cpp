// TIMEDlg.cpp: 实现文件
//

#include "pch.h"
#include "SmartLuoJia2.0.h"
#include "afxdialogex.h"
#include "TIMEDlg.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>

// TIMEDlg 对话框

IMPLEMENT_DYNAMIC(TIMEDlg, CDialogEx)

TIMEDlg::TIMEDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_TIME, pParent)
{
}

TIMEDlg::~TIMEDlg()
{
}

void TIMEDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_START_COMBO, startCombo);
    DDX_Control(pDX, IDC_END_COMBO, endCombo);
}

BEGIN_MESSAGE_MAP(TIMEDlg, CDialogEx)
    ON_BN_CLICKED(IDC_OKBUTTON, &TIMEDlg::OnOKButtonClicked)
END_MESSAGE_MAP()

// TIMEDlg 消息处理程序

BOOL TIMEDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // 获取当前时间
    std::time_t now = std::time(nullptr);
    std::tm* currentTime = std::localtime(&now);
    std::tm currentTm = *currentTime;
    currentTm.tm_sec = 0;

    // 读取seats.txt获取座位预约信息
    std::vector<std::string> seatsLines;
    std::ifstream seatsFile(".//library_inf//seats.txt");
    if (seatsFile.is_open()) {
        std::string line;
        while (std::getline(seatsFile, line)) {
            seatsLines.push_back(line);
        }
        seatsFile.close();
    }

    // 查找该座位在对应区域的最早预约开始时间
    std::string earliestStartTime;
    bool inTargetArea = false;
    for (size_t i = 0; i < seatsLines.size(); ++i) {
        const auto& line = seatsLines[i];

        if (line == "#") {
            // 新区域开始，下一行是区域名
            if (i + 1 < seatsLines.size()) {
                inTargetArea = (seatsLines[i + 1] == name);
                i++; // 跳过区域名行
            }
            continue;
        }

        if (inTargetArea) {
            std::istringstream iss(line);
            int seat;
            std::string start, end;
            if (iss >> seat >> start >> end) {
                if (seat == m_seatNumber) {
                    std::tm startTm = parseTime(start);
                    std::tm endTm = parseTime(end);
                    // 只考虑未来的预约
                    if (compareTime(currentTm, endTm)) {
                        if (earliestStartTime.empty() || compareTime(startTm, parseTime(earliestStartTime))) {
                            earliestStartTime = start;
                        }
                    }
                }
            }
        }
    }

    // 设置组合框默认文本
    startCombo.ResetContent();
    startCombo.AddString(_T("请选择起始时间"));
    startCombo.SetCurSel(0);

    endCombo.ResetContent();
    endCombo.AddString(_T("请选择结束时间"));
    endCombo.SetCurSel(0);

    // 计算第一个可选时间点（当前时间+30分钟，取整）
    int currentHour = currentTm.tm_hour;
    int currentMin = currentTm.tm_min;

    // 确保最早不早于8:00
    const int EARLIEST_HOUR = 8;
    const int EARLIEST_MIN = 0;
    if (currentHour < EARLIEST_HOUR ||
        (currentHour == EARLIEST_HOUR && currentMin < EARLIEST_MIN)) {
        currentHour = EARLIEST_HOUR;
        currentMin = EARLIEST_MIN;
    }

    // 计算初始时间（30分钟间隔）
    int startMin = ((currentMin + 29) / 30) * 30; // 向上取整到30分钟间隔
    if (startMin >= 60) {
        startMin = 0;
        currentHour++;
    }

    // 确保最晚不超过22:30
    int MAX_HOUR = 22;
    int MAX_MIN = 30;

    // 如果有更早的预约时间，调整最大可选时间
    if (!earliestStartTime.empty()) {
        std::tm earliestTm = parseTime(earliestStartTime);
        if (compareTime(earliestTm, { 0, MAX_MIN, MAX_HOUR })) {
            MAX_HOUR = earliestTm.tm_hour;
            MAX_MIN = earliestTm.tm_min;
        }
    }

    // 生成起始时间选项
    for (int hour = currentHour; hour <= MAX_HOUR; hour++) {
        int minStart = (hour == currentHour) ? startMin : 0;
        int minEnd = (hour == MAX_HOUR) ? MAX_MIN : 30;

        for (int min = minStart; min <= minEnd; min += 30) {
            CString timeStr;
            timeStr.Format(_T("%02d:%02d"), hour, min);
            startCombo.AddString(timeStr);
        }
    }
    // 生成结束时间选项
    for (int hour = currentHour; hour <= MAX_HOUR; hour++) {
        int minStart = (hour == currentHour) ? startMin : 0;
        int minEnd = (hour == MAX_HOUR) ? MAX_MIN : 30;

        for (int min = minStart; min <= minEnd; min += 30) {
            CString timeStr;
            timeStr.Format(_T("%02d:%02d"), hour, min);
            endCombo.AddString(timeStr);
        }
    }

    return TRUE;
}

void TIMEDlg::OnOKButtonClicked()
{
    int startIndex = startCombo.GetCurSel();
    int endIndex = endCombo.GetCurSel();
    if (startIndex >= 0 && endIndex >= 0) {
        CString startStr, endStr;
        startCombo.GetLBText(startIndex, startStr);
        endCombo.GetLBText(endIndex, endStr);
        startTime = CW2A(startStr.GetString());
        endTime = CW2A(endStr.GetString());

        // 额外检查选择的是否是默认提示文本（虽然理论上不会发生）
        if (startStr == _T("请选择起始时间") || endStr == _T("请选择结束时间")) {
            MessageBox(_T("请选择预约时间段"), _T("提示"), MB_OK | MB_ICONINFORMATION);
            return;
        }
        // 保存到seats.txt文件
        std::vector<std::string> seatsLines;
        std::ifstream seatsFile(".//library_inf//seats.txt");
        if (seatsFile.is_open()) {
            std::string line;
            while (std::getline(seatsFile, line)) {
                seatsLines.push_back(line);
            }
            seatsFile.close();
        }

        // 格式化座位号为三位数
        std::string formattedSeat = (m_seatNumber < 10) ? "00" + std::to_string(m_seatNumber) :
            (m_seatNumber < 100) ? "0" + std::to_string(m_seatNumber) :
            std::to_string(m_seatNumber);

        bool seatFound = false;
        bool inTargetArea = false;
        for (size_t i = 0; i < seatsLines.size(); ++i) {
            if (seatsLines[i] == "#") {
                inTargetArea = (i + 1 < seatsLines.size() && seatsLines[i + 1] == name);
                continue;
            }

            if (inTargetArea) {
                std::istringstream iss(seatsLines[i]);
                int seat;
                std::string start, end;
                if (iss >> seat >> start >> end) {
                    if (seat == m_seatNumber) {
                        seatsLines[i] = formattedSeat + " " + startTime + " " + endTime;
                        seatFound = true;
                        break;
                    }
                }
            }
        }

        if (!seatFound) {
            // 查找目标区域位置
            bool areaFound = false;
            for (size_t i = 0; i < seatsLines.size(); ++i) {
                if (seatsLines[i] == "#" && i + 1 < seatsLines.size() && seatsLines[i + 1] == name) {
                    // 找到区域结束位置
                    size_t insertPos = i + 2;
                    while (insertPos < seatsLines.size() && seatsLines[insertPos] != "#") {
                        insertPos++;
                    }
                    seatsLines.insert(seatsLines.begin() + insertPos, formattedSeat + " " + startTime + " " + endTime);
                    areaFound = true;
                    break;
                }
            }

            if (!areaFound) {
                // 添加新区域
                seatsLines.push_back("#");
                seatsLines.push_back(name);
                seatsLines.push_back(formattedSeat + " " + startTime + " " + endTime);
            }
        }

        // 写入文件
        std::ofstream seatsOutFile(".//library_inf//seats.txt");
        if (seatsOutFile.is_open()) {
            for (const auto& line : seatsLines) {
                seatsOutFile << line << std::endl;
            }
            seatsOutFile.close();
        }

        // 保存到my_record.txt文件
        std::vector<std::string> recordLines;
        std::ifstream recordFile(".//library_inf//my_record.txt");
        if (recordFile.is_open()) {
            std::string line;
            while (std::getline(recordFile, line)) {
                recordLines.push_back(line);
            }
            recordFile.close();
        }

        // 获取当前日期
        std::time_t now = std::time(nullptr);
        std::tm* currentTime = std::localtime(&now);

        // 添加新记录
        recordLines.push_back("#");
        recordLines.push_back(name);
        std::ostringstream recordIss;
        string seatstr=to_string(m_seatNumber);
        if (seatstr.size() == 1)
        {
            seatstr = "00" + seatstr;
        }
        else
        {
            seatstr = "0" + seatstr;
        }
        recordIss << CT2A(ID.GetString()) << " " << seatstr << " "
            << (currentTime->tm_mon + 1) << " " << currentTime->tm_mday << " "
            << startTime << " " << endTime;
        recordLines.push_back(recordIss.str());

        std::ofstream recordOutFile(".//library_inf//my_record.txt");
        if (recordOutFile.is_open()) {
            for (const auto& line : recordLines) {
                recordOutFile << line << std::endl;
            }
            recordOutFile.close();
        }

        EndDialog(IDOK);
    }
    else {
        MessageBox(_T("请选择起始时间和结束时间"), _T("提示"), MB_OK | MB_ICONINFORMATION);
    }
}