// Rectangle.cpp: implementation of the CRectangle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CAD.h"
#include "Rectangle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CRectangle, CObject, 1)

CRectangle::CRectangle()
:m_ptBegin(0, 0), m_ptEnd(0, 0)
{

}

CRectangle::~CRectangle()
{

}

void CRectangle::OnDraw(CDC *pDC)
{
  CPen pen(m_pen.m_nPenStyle, m_pen.m_nWidth, m_pen.m_crColor);
  pDC->SelectObject(pen);
  //CBrush brush(RGB(255, 0, 0));
  //pDC->SelectObject(brush);
  pDC->SelectObject(::GetStockObject(NULL_BRUSH));
  pDC->Rectangle(m_ptBegin.x, m_ptBegin.y, 
                 m_ptEnd.x, m_ptEnd.y);
}

void CRectangle::OnLButtonDown(UINT nFlags, CPoint point)
{
  m_ptBegin = point;
}

void CRectangle::OnLButtonUp(UINT nFlags, CPoint point)
{
  m_ptEnd = point;
}

void CRectangle::OnMouseMove(UINT nFlags, CPoint point)
{
  m_ptEnd = point;
}

void CRectangle::SetPen(CMyPen pen)
{
  m_pen = pen;
}

BOOL CRectangle::IsSelect(CPoint pt)
{
  CRgn rgn;

  rgn.CreateRectRgn(m_ptBegin.x, m_ptBegin.y, m_ptEnd.x, m_ptEnd.y);
  return rgn.PtInRegion(pt);
}

void CRectangle::OnDrawSelect(CDC *pDC)
{
  CPen pen(m_pen.m_nPenStyle, m_pen.m_nWidth, RGB(255, 0, 0));
  pDC->SelectObject(pen);
  pDC->SelectObject(::GetStockObject(NULL_BRUSH));
  pDC->Rectangle(m_ptBegin.x, m_ptBegin.y, 
                 m_ptEnd.x, m_ptEnd.y);
}
