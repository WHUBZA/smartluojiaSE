#pragma once
#include <afxwin.h>
// ʹ�õ�¼��ťΪ��ɫ
class CColorButton :
    public CButton
{
public:
    DECLARE_MESSAGE_MAP()

    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) override; // ������д
};

