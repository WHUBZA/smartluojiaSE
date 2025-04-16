#include "pch.h"
#include "ButtonST.h"
// 按钮自定义+DPI缩放
IMPLEMENT_DYNAMIC(CButtonST, CButton)

CButtonST::CButtonST()
{
    m_bFlat = FALSE;
    m_bDrawCaption = TRUE;
}

CButtonST::~CButtonST()
{
}

BEGIN_MESSAGE_MAP(CButtonST, CButton)
    ON_WM_DRAWITEM()
END_MESSAGE_MAP()

float CButtonST::GetDPIScaleFactor()
{
    HDC hDC = ::GetDC(NULL);
    int nDPI = ::GetDeviceCaps(hDC, LOGPIXELSX);
    ::ReleaseDC(NULL, hDC);
    return static_cast<float>(nDPI) / 96.0f;
}

void CButtonST::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
    CRect rect = lpDrawItemStruct->rcItem;
    UINT state = lpDrawItemStruct->itemState;

    // 绘制背景
    if (m_bFlat)
    {
        if (state & ODS_SELECTED)
        {
            pDC->FillSolidRect(rect, RGB(200, 200, 200)); // 点击时变暗
        }
        else
        {
            pDC->FillSolidRect(rect, GetSysColor(COLOR_BTNFACE));
        }
    }
    else
    {
        CButton::DrawItem(lpDrawItemStruct);
    }

    // 绘制图标
    DrawIcon(pDC, rect);

    // 绘制标题
    if (m_bDrawCaption)
    {
        DrawCaption(pDC, rect);
    }
}

void CButtonST::DrawIcon(CDC* pDC, CRect& rect)
{
    if (!m_Icon.IsNull())
    {
        float scaleFactor = GetDPIScaleFactor();
        const int MAX_ICON_WIDTH = 70;  // 可以根据需要调整这个值
        const int MAX_ICON_HEIGHT = 70; // 可以根据需要调整这个值

        int nOriginalWidth = m_Icon.GetWidth();
        int nOriginalHeight = m_Icon.GetHeight();

        float fScaleX = (float)(MAX_ICON_WIDTH * scaleFactor) / nOriginalWidth;
        float fScaleY = (float)(MAX_ICON_HEIGHT * scaleFactor) / nOriginalHeight;
        float fScale = min(fScaleX, fScaleY);

        int nWidth = static_cast<int>(nOriginalWidth * fScale);
        int nHeight = static_cast<int>(nOriginalHeight * fScale);
        int x = rect.left + (rect.Width() - nWidth) / 2;
        int y = rect.top + (rect.Height() - nHeight) / 2;

        m_Icon.Draw(pDC->m_hDC, x, y, nWidth, nHeight);
    }
}

void CButtonST::DrawCaption(CDC* pDC, CRect& rect)
{
    CString strText;
    GetWindowText(strText);
    if (!strText.IsEmpty())
    {
        pDC->SetBkMode(TRANSPARENT);
        pDC->DrawText(strText, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
}

void CButtonST::SetIcon(CImage& img)
{
    m_Icon.Destroy();
    m_Icon.Attach(img.Detach());
    Invalidate();
}

void CButtonST::SetFlat(BOOL bFlat)
{
    m_bFlat = bFlat;
    Invalidate();
}

void CButtonST::SetDrawCaption(BOOL bDrawCaption)
{
    m_bDrawCaption = bDrawCaption;
    Invalidate();
}