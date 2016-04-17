// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyCAD.h"
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
	:m_Start(0, 0), m_End(0, 0)
{

}

CLine::~CLine()
{

}
void CLine::OnDraw(CDC *pDc)
{
	pDc->MoveTo(m_Start);
	pDc->LineTo(m_End);
}

int CLine::OnButtonDown(UINT nFlags, CPoint point)
{
	m_Start = point;
	return 0;
}
int CLine::OnButtonUp(UINT nFlags, CPoint point)
{
	m_End = point;
	return 0;
}
int CLine::OnMouseMove(UINT nFlags, CPoint point)
{
	m_End = point;
	return 0;
}
