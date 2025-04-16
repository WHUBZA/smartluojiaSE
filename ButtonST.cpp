#include "pch.h"
#include "ButtonST.h"
// ��ť�Զ���+DPI����
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

    // ���Ʊ���
    if (m_bFlat)
    {
        if (state & ODS_SELECTED)
        {
            pDC->FillSolidRect(rect, RGB(200, 200, 200)); // ���ʱ�䰵
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

    // ����ͼ��
    DrawIcon(pDC, rect);

    // ���Ʊ���
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
        const int MAX_ICON_WIDTH = 70;  // ���Ը�����Ҫ�������ֵ
        const int MAX_ICON_HEIGHT = 70; // ���Ը�����Ҫ�������ֵ

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