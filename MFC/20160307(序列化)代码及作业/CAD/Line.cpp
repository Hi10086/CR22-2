// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CAD.h"
#include "Line.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CLine, CObject, 1)

CLine::CLine()
:m_ptBegin(0, 0), m_ptEnd(0, 0)
{

}

CLine::~CLine()
{

}

void CLine::OnDraw(CDC *pDC)
{
  try
  {
    CPen pen(m_pen.m_nPenStyle, m_pen.m_nWidth, m_pen.m_crColor);
    pDC->SelectObject(pen);
    pDC->MoveTo(m_ptBegin);
    pDC->LineTo(m_ptEnd);
  }
  catch (CResourceException  *e)
  {
    //...
  }
}

void CLine::OnLButtonDown(UINT nFlags, CPoint point)
{
  m_ptBegin = point;
}

void CLine::OnLButtonUp(UINT nFlags, CPoint point)
{
  m_ptEnd = point;
}

void CLine::OnMouseMove(UINT nFlags, CPoint point)
{
  m_ptEnd = point;
}


void CLine::SetPen(CMyPen pen)
{
  m_pen = pen;
}

BOOL CLine::IsSelect(CPoint pt)
{
  CRgn rgn;
  CPoint Points[4];
  Points[0].x = m_ptBegin.x;
  Points[0].y = m_ptBegin.y - 5;
  Points[1].x = m_ptBegin.x;
  Points[1].y = m_ptBegin.y + 5;
  Points[2].x = m_ptEnd.x;
  Points[2].y = m_ptEnd.y + 5;
  Points[3].x = m_ptEnd.x;
  Points[3].y = m_ptEnd.y - 5;

  rgn.CreatePolygonRgn(Points, 4, ALTERNATE);
  
  return rgn.PtInRegion(pt);
}

void CLine::OnDrawSelect(CDC *pDC)
{
  try
  {
    CPen pen(m_pen.m_nPenStyle, m_pen.m_nWidth, RGB(255, 0, 0));
    pDC->SelectObject(pen);
    pDC->MoveTo(m_ptBegin);
    pDC->LineTo(m_ptEnd);
  }
  catch (CResourceException  *e)
  {
    //...
  }
}