// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SankCAD.h"
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
	:m_StartPos(0, 0), m_EndPos(0, 0), m_MovePos(0, 0)
{

}

CLine::~CLine()
{

}

IMPLEMENT_SERIAL(CLine, CObject, 1)

IShape* CLine::OnCopy()
{
	CLine *pLine = new CLine();
	pLine->m_EndPos = m_EndPos;
	pLine->m_MovePos = m_MovePos;
	pLine->m_StartPos = m_StartPos;
	return pLine;
}

TagShape CLine::GetData()
{
	TagShape ret;
	ret.m_EndPos = m_EndPos;
	ret.m_StartPos = m_StartPos;
	ret.m_MovePos = m_MovePos;

	return ret;
}
void CLine::SetData(TagShape& obj)
{
	m_EndPos = obj.m_EndPos;
	m_StartPos = obj.m_StartPos;
	m_MovePos = obj.m_MovePos;
}

int CLine::OnDraw(CDC *pDC)
{
	CPen pen(PS_SOLID , 1, RGB(0, 0, 0));
	pDC->SelectObject(pen);

	pDC->MoveTo(m_StartPos);
	pDC->LineTo(m_EndPos);
	return 0;
}

BOOL CLine::IsSelect(UINT nFlags, CPoint point)
{
	CRgn rgn;
	CPoint Points[4];

	if (m_StartPos.x - m_EndPos.x > m_StartPos.y - m_EndPos.y)
	{
		Points[0].x = m_StartPos.x;
		Points[0].y = m_StartPos.y - 5;
		Points[1].x = m_StartPos.x;
		Points[1].y = m_StartPos.y + 5;
		Points[2].x = m_EndPos.x;
		Points[2].y = m_EndPos.y + 5;
		Points[3].x = m_EndPos.x;
		Points[3].y = m_EndPos.y - 5;
	}
	else
	{
		Points[0].x = m_StartPos.x - 5;
		Points[0].y = m_StartPos.y;
		Points[1].x = m_StartPos.x + 5;
		Points[1].y = m_StartPos.y;
		Points[2].x = m_EndPos.x + 5;
		Points[2].y = m_EndPos.y;
		Points[3].x = m_EndPos.x - 5;
		Points[3].y = m_EndPos.y;
	}
	
	rgn.CreatePolygonRgn(Points, 4, ALTERNATE);
	if (rgn.PtInRegion(point))
	{
		m_MovePos = point;
		return TRUE;
	}
	return FALSE;
}

int CLine::OnButtonDown(UINT nFlags, CPoint point)
{
	m_StartPos = point;
	return 0;
}

int CLine::OnButtonUp(UINT nFlags, CPoint point)
{
	m_EndPos = point;
	return 0;
}

int CLine::OnMouseMove(UINT nFlags, CPoint point)
{
	m_EndPos = point;
	return 0;
}

int CLine::OnMove(UINT nFlags, CPoint point)
{
	m_StartPos = m_StartPos + (point - m_MovePos);
	m_EndPos = m_EndPos + (point - m_MovePos);
	m_MovePos = point;

	return 0;
}

void CLine::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_StartPos
		   << m_EndPos
		   << m_MovePos;
	}
	else
	{
		// TODO: add loading code here
		ar >> m_StartPos
		   >> m_EndPos
		   >> m_MovePos;
	}
}

void CLine::OnDrawSelect(CDC *pDC)
{
	try
	{
		CPen pen(PS_DASH , 1, RGB(255, 255, 0));
		pDC->SelectObject(pen);
		pDC->MoveTo(m_StartPos);
		pDC->LineTo(m_EndPos);
	}
	catch (CResourceException  *e)
	{
		//...
	}	
}

