// MyButton.cpp : implementation file
//

#include "stdafx.h"
#include "CTL2.h"
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
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyButton message handlers

void CMyButton::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
  AfxMessageBox("我被按了");
	CButton::OnKeyDown(nChar, nRepCnt, nFlags);
}
