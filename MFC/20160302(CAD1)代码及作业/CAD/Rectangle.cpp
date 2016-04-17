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

CRectangle::CRectangle()
:m_ptBegin(0, 0), m_ptEnd(0, 0)
{

}

CRectangle::~CRectangle()
{

}

void CRectangle::OnDraw(CDC *pDC)
{
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

