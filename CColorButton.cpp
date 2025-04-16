#include "pch.h"
#include "CColorButton.h"

void CColorButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
    CRect rect = lpDrawItemStruct->rcItem;
    UINT state = lpDrawItemStruct->itemState;

    // 1. ���ñ���ɫ����ɫ��
    CBrush brush(RGB(39, 160, 134)); // ����ɫ
    pDC->FillRect(&rect, &brush);

    // 2. ����������ɫ����ɫ��
    pDC->SetTextColor(RGB(255, 255, 255));
    pDC->SetBkMode(TRANSPARENT); // ͸������

    // 3. ��ȡ��ť�ı�
    CString strText;
    GetWindowText(strText);

    // 4. �����ı������У�
    pDC->DrawText(strText, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    // 5. ���Ʊ߿򣨿�ѡ��
    if (state & ODS_SELECTED)
        pDC->Draw3dRect(&rect, RGB(0, 64, 0), RGB(0, 200, 0)); // ����Ч��
    else
        pDC->Draw3dRect(&rect, RGB(0, 200, 0), RGB(0, 64, 0)); // ����״̬
}

// ��Ϣӳ�䣨�������գ���Ϊ DrawItem ���麯����
BEGIN_MESSAGE_MAP(CColorButton, CButton)
END_MESSAGE_MAP()