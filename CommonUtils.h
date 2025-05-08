// CommonUtils.h
#pragma once
#include <ctime>
#include <string>
bool compareTime(const std::tm& time1, const std::tm& time2);
std::tm parseTime(const std::string& timeStr);