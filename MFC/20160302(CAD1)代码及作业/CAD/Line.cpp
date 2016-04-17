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

CLine::CLine()
:m_ptBegin(0, 0), m_ptEnd(0, 0)
{

}

CLine::~CLine()
{

}

void CLine::OnDraw(CDC *pDC)
{
  pDC->MoveTo(m_ptBegin);
  pDC->LineTo(m_ptEnd);
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
