// MyEdit.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "MyEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyEdit

CMyEdit::CMyEdit()
{
}

CMyEdit::~CMyEdit()
{
}


BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
	//{{AFX_MSG_MAP(CMyEdit)
	ON_WM_CTLCOLOR_REFLECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyEdit message handlers

HBRUSH CMyEdit::CtlColor(CDC* pDC, UINT nCtlColor) 
{
  static CBrush brush(RGB(255, 0, 0));

  pDC->SetBkColor(RGB(0, 0, 255));
  pDC->SetTextColor(RGB(0, 255, 0));
  return brush;
}
