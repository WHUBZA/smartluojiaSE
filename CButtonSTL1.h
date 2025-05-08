#pragma once
#include <afxwin.h>
#include <atlimage.h>

class CButtonSTL1 : public CButton
{
    DECLARE_DYNAMIC(CButtonSTL1)

public:
    CButtonSTL1();
    CButtonSTL1(int width,int height);
    virtual ~CButtonSTL1();

protected:
    DECLARE_MESSAGE_MAP()
    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
    void DrawIcon(CDC* pDC, CRect& rect);
    void DrawCaption(CDC* pDC, CRect& rect);
    CImage m_Icon;
    BOOL m_bFlat;
    BOOL m_bDrawCaption;
    float GetDPIScaleFactor();
    int WIDTH, HEIGHT;

public:
    void SetIcon(CImage& img);
    void SetFlat(BOOL bFlat);
    void SetDrawCaption(BOOL bDrawCaption);
    bool flag = true;
    void setPicture(int width, int height);
};