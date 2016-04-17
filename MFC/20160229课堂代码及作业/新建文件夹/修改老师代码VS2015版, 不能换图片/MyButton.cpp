// MyButton.cpp : implementation file
//

#include "stdafx.h"
#include "Create.h"
#include "MyButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyButton

CMyButton::CMyButton()
{
	
}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CButton)
//{{AFX_MSG_MAP(CMyButton)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyButton message handlers

// void CMyButton::OnPaint() 
// {
// 	CPaintDC dc(this); // device context for painting
// 
//   //´´½¨ÄÚ´ædc
//   CDC MemDC;
//   MemDC.CreateCompatibleDC(&dc);
// 
//   CBitmap bitmap;
//   bitmap.LoadBitmap(IDB_BITMAP1);
//   MemDC.SelectObject(bitmap);
// 
//   dc.BitBlt(0, 0, 157, 59, &MemDC, 0, 0, SRCCOPY); 
// 
// 	//dc.TextOut(0, 0, "test");
//  
// 	// Do not call CButton::OnPaint() for painting messages
// }

void CMyButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{ 
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);
    
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);
	
	CBitmap bitmap;
	if (lpDrawItemStruct->itemAction == ODA_SELECT || lpDrawItemStruct->itemState == ODS_DISABLED)
	{

		bitmap.LoadBitmap(IDB_BITMAP7);
		MemDC.SelectObject(bitmap);
		this->EnableWindow(FALSE);

	}
	else
	{
		bitmap.LoadBitmap(IDB_BITMAP4);
		MemDC.SelectObject(bitmap);
	}
	
	
	dc.BitBlt(0, 0, 18, 18, &MemDC, 0, 0, SRCCOPY); 
	dc.Detach();
	
	//   UINT uStyle = DFCS_BUTTONPUSH;
	//   
	//   // This code only works with buttons.
	//   ASSERT(lpDrawItemStruct->CtlType == ODT_BUTTON);
	//   
	//   // If drawing selected, add the pushed style to DrawFrameControl.
	//   if (lpDrawItemStruct->itemState & ODS_SELECTED)
	//     uStyle |= DFCS_PUSHED;
	//   
	//   // Draw the button frame.
	//   ::DrawFrameControl(lpDrawItemStruct->hDC, &lpDrawItemStruct->rcItem, 
	//     DFC_BUTTON, uStyle);
	//   
	//   // Get the button's text.
	//   CString strText;
	//   GetWindowText(strText);
	//   
	//   // Draw the button text using the text color red.
	//   COLORREF crOldColor = ::SetTextColor(lpDrawItemStruct->hDC, RGB(255,0,0));
	//   ::DrawText(lpDrawItemStruct->hDC, strText, strText.GetLength(), 
	//     &lpDrawItemStruct->rcItem, DT_SINGLELINE|DT_VCENTER|DT_CENTER);
	//   ::SetTextColor(lpDrawItemStruct->hDC, crOldColor);
	
}
