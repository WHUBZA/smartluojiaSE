#pragma once
#include <afxwin.h>
// 使得登录按钮为绿色
class CColorButton2 :
    public CButton
{
public:
    DECLARE_MESSAGE_MAP()

    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) override; // 必须重写
};


