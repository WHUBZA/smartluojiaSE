﻿// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H

// 添加要在此处预编译的标头
#include "framework.h"
#include<vector>
#include<string>
#include<fstream>
#include"UserInf.h"
#include <atlconv.h> // 将CString类转化为string类
#include"CColorButton.h"
#include"MENU2Dlg.h"
#include"GRADEDLG.h"
#include"COURSEDLG.h"
#include"DATESETDLG.h"
#include<atlimage.h>
#include <gdiplus.h>
#include "ButtonST.h" 
#include<windows.h>
#include <winresrc.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "LIBRARYSELECTDlg.h"
#include "LIBRARY1Dlg.h"
#include "CButtonSTL1.h"
#include "RECORDDlg.h"
#include "TIMEDlg.h"
#include "LIBRARY3Dlg.h"
#include "LIBRARY2Dlg.h"
#include "CommonUtils.h"
#pragma comment(lib, "gdiplus.lib")
#endif //PCH_H
