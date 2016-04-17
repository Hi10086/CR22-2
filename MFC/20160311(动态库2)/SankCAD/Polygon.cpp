// Polygon.cpp: implementation of the CPolygon class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SankCAD.h"
#include "Polygon.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPolygon::CPolygon()
{
	m_nNum = 0;
	m_pStartPos = NULL;
}

CPolygon::CPolygon(CPolygon& obj)
	:m_nNum(obj.m_nNum), m_pStartPos(obj.m_pStartPos)
{
	m_ArrayPoints.Copy(obj.m_ArrayPoints);
}

CPolygon::~CPolygon()
{

}

IMPLEMENT_SERIAL(CPolygon, CObject, 1)

IShape* CPolygon::OnCopy()
{
	return new CPolygon(*this);
}

void CPolygon::SetData(TagShape& obj)
{
	m_ArrayPoints.Copy(obj.m_ArrayPoints);
	m_nNum = obj.m_nNum;
	m_pStartPos = NULL;
}

TagShape CPolygon::GetData()
{
	TagShape ret;
	ret.m_ArrayPoints.Copy(m_ArrayPoints);
	ret.m_nNum = m_nNum;
	ret.m_pStartPos = NULL;

	return ret;
}

int CPolygon::OnDraw(CDC *pDc)
{
	for (int i = 0; i + 1 < m_ArrayPoints.GetSize(); i++)
	{
		pDc->MoveTo(m_ArrayPoints[i]);
		pDc->LineTo(m_ArrayPoints[i+1]);
	}

	if (m_pStartPos != NULL)
	{
		CBrush brush(RGB(0, 0, 0));
		pDc->FillRgn(m_pStartPos, &brush);
	}
	return 0;
}

BOOL CPolygon::IsSelect(UINT nFlags, CPoint point)
{
	return true;
}

int CPolygon::OnButtonDown(UINT nFlags, CPoint point)
{
	m_ArrayPoints.SetAtGrow(m_nNum, point);
	if (m_nNum == 0)
	{
		m_pStartPos = new CRgn();
		m_pStartPos->CreateRectRgn(m_ArrayPoints[0].x - 5, m_ArrayPoints[0].y - 5, \
			m_ArrayPoints[0].x + 5, m_ArrayPoints[0].y + 5);
	}
	++m_nNum;
	return 0;
}
int CPolygon::OnButtonUp(UINT nFlags, CPoint point)
{
	if (m_pStartPos->PtInRegion(point))
	{
		m_ArrayPoints.SetAtGrow(m_nNum, m_ArrayPoints[0]);
		delete m_pStartPos;
		m_pStartPos = NULL;
		return 0;
	}
	else
	{
		m_ArrayPoints.SetAtGrow(m_nNum, point);
		++m_nNum;
		return m_nNum;
	}
}

int CPolygon::OnMouseMove(UINT nFlags, CPoint point)
{
	m_ArrayPoints.SetAtGrow(m_nNum, point);
	return 0;
}

int CPolygon::OnMove(UINT nFlags, CPoint point)
{
	return 0;
}

void CPolygon::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		int nNum = m_ArrayPoints.GetSize();
		ar.Write((char *)&nNum, sizeof(nNum));
		for (int i = 0; i < m_ArrayPoints.GetSize(); i++)
		{
			ar << m_ArrayPoints[i];
		}
	}
	else
	{
		// TODO: add loading code here
		int nNum = 0;
		ar.Read((char *)&nNum, sizeof(nNum));
		CPoint point;
		for (int i = 0; i < nNum; i++)
		{
			ar >> point;
			m_ArrayPoints.Add(point);
		}
	}

}

void CPolygon::OnDrawSelect(CDC *pDC)
{
	try
	{
		CPen pen(PS_DASH , 1, RGB(255, 255, 0));
		pDC->SelectObject(pen);
		OnDraw(pDC);
	}
	catch (CResourceException  *e)
	{
		//...
	}
}
