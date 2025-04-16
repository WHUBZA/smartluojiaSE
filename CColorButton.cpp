#include "pch.h"
#include "CColorButton.h"

void CColorButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
    CRect rect = lpDrawItemStruct->rcItem;
    UINT state = lpDrawItemStruct->itemState;

    // 1. 设置背景色（绿色）
    CBrush brush(RGB(39, 160, 134)); // 深绿色
    pDC->FillRect(&rect, &brush);

    // 2. 设置字体颜色（白色）
    pDC->SetTextColor(RGB(255, 255, 255));
    pDC->SetBkMode(TRANSPARENT); // 透明背景

    // 3. 获取按钮文本
    CString strText;
    GetWindowText(strText);

    // 4. 绘制文本（居中）
    pDC->DrawText(strText, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    // 5. 绘制边框（可选）
    if (state & ODS_SELECTED)
        pDC->Draw3dRect(&rect, RGB(0, 64, 0), RGB(0, 200, 0)); // 按下效果
    else
        pDC->Draw3dRect(&rect, RGB(0, 200, 0), RGB(0, 64, 0)); // 正常状态
}

// 消息映射（可以留空，因为 DrawItem 是虚函数）
BEGIN_MESSAGE_MAP(CColorButton, CButton)
END_MESSAGE_MAP()