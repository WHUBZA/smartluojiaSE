#pragma once
#include <afxwin.h>
#include <atlimage.h>

class CButtonST : public CButton
{
    DECLARE_DYNAMIC(CButtonST)

public:
    CButtonST();
    virtual ~CButtonST();

protected:
    DECLARE_MESSAGE_MAP()
    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
    void DrawIcon(CDC* pDC, CRect& rect);
    void DrawCaption(CDC* pDC, CRect& rect);
    CImage m_Icon;
    BOOL m_bFlat;
    BOOL m_bDrawCaption;
    float GetDPIScaleFactor();

public:
    void SetIcon(CImage& img);
    void SetFlat(BOOL bFlat);
    void SetDrawCaption(BOOL bDrawCaption);
};