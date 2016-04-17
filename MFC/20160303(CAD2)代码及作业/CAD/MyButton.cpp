// MyButton.cpp : implementation file
//

#include "stdafx.h"
#include "CAD.h"
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
  m_crBackground = 0;
}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CButton)
	//{{AFX_MSG_MAP(CMyButton)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyButton message handlers

void CMyButton::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
  CRect rc;
  GetClientRect(&rc);
	CBrush brush(m_crBackground);
	dc.FillRect(rc, &brush);
	// Do not call CButton::OnPaint() for painting messages
}
