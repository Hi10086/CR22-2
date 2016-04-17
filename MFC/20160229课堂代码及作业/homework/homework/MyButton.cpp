// MyButton.cpp : 实现文件
//

#include "stdafx.h"
#include "homework.h"
#include "MyButton.h"


// CMyButton

IMPLEMENT_DYNAMIC(CMyButton, CButton)

CMyButton::CMyButton()
{

}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CButton)
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()



// CMyButton 消息处理程序




void CMyButton::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap bitmap;

	if (lpDrawItemStruct->itemAction == ODA_SELECT 
		|| lpDrawItemStruct->itemState == ODS_DISABLED)
	{
		bitmap.LoadBitmap(IDB_BITMAP1);
		memDC.SelectObject(bitmap);
		this->EnableWindow(FALSE);
	}
	else
	{
		bitmap.LoadBitmap(IDB_BITMAP4);
		memDC.SelectObject(bitmap);
	}

	dc.BitBlt(0, 0, 18, 18, &memDC, 0, 0, SRCCOPY);
	dc.Detach();
}
