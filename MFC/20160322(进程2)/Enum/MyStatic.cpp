// MyStatic.cpp : implementation file
//

#include "stdafx.h"
#include "Enum.h"
#include "MyStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyStatic

CMyStatic::CMyStatic()
{
  m_hNewCursor = LoadCursor(AfxGetInstanceHandle(), (LPSTR)IDC_CURSOR1);
  m_IsDown = FALSE;
  m_hWnd = NULL;
}

CMyStatic::~CMyStatic()
{
}


BEGIN_MESSAGE_MAP(CMyStatic, CStatic)
	//{{AFX_MSG_MAP(CMyStatic)
	ON_WM_LBUTTONDOWN()
	ON_WM_NCMBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyStatic message handlers

void CMyStatic::OnLButtonDown(UINT nFlags, CPoint point) 
{
  if (!m_IsDown)
  {
    ::SetCursor(m_hNewCursor);
    ::SetCapture(GetSafeHwnd());
    m_IsDown = TRUE;
  }
}

void CMyStatic::OnNcMButtonUp(UINT nHitTest, CPoint point) 
{
	CStatic::OnNcMButtonUp(nHitTest, point);
}

void CMyStatic::OnLButtonUp(UINT nFlags, CPoint point) 
{
  if (m_IsDown)
  {
    ::ReleaseCapture();
    m_IsDown = FALSE;
    DrawWindowFrame(m_hWnd);
  }
  
  
	CStatic::OnLButtonUp(nFlags, point);
}

void CMyStatic::OnMouseMove(UINT nFlags, CPoint point) 
{
  if (m_IsDown)
  {
    ClientToScreen(&point);
    
    HWND hWnd = ::WindowFromPoint(point);
    if (hWnd != m_hWnd)
    {
      //绘制原来
      DrawWindowFrame(m_hWnd);

      //绘制新的
      DrawWindowFrame(hWnd);
      m_hWnd = hWnd;
    }
  }    


	CStatic::OnMouseMove(nFlags, point);
}

void CMyStatic::DrawWindowFrame(HWND hWnd)
{
  if (hWnd == NULL)
    return;

  CRect rc;
  HDC hdc;
  ::GetClientRect(hWnd, &rc);
  hdc = ::GetDC(hWnd);
  HPEN hPen = ::CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
  ::SelectObject(hdc, hPen);
  ::SelectObject(hdc, ::GetStockObject(NULL_BRUSH));
  ::SetROP2(hdc, R2_XORPEN); //笔异或
  ::Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
  ::ReleaseDC(hWnd, hdc);
  ::DeleteObject(hPen);
}
