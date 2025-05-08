// CommonUtils.cpp
#include "pch.h"
#include "CommonUtils.h"
#include <sstream>
#include <iomanip>
bool compareTime(const std::tm& time1, const std::tm& time2) {
    if (time1.tm_hour < time2.tm_hour) return true;
    if (time1.tm_hour > time2.tm_hour) return false;
    return time1.tm_min < time2.tm_min;
}

std::tm parseTime(const std::string& timeStr) {
    std::tm tm = {};
    std::istringstream iss(timeStr);
    iss >> std::get_time(&tm, "%H:%M");
    return tm;
}