// Polygon.h: interface for the CPolygon class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POLYGON_H__48A9336B_6857_40D4_A2B1_20CCB480048A__INCLUDED_)
#define AFX_POLYGON_H__48A9336B_6857_40D4_A2B1_20CCB480048A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IShape.h"
#include <afxtempl.h>

class CPolygon : public IShape  
{
	DECLARE_SERIAL(CPolygon)
public:
	CPolygon();
	CPolygon(CPolygon& obj);
	virtual ~CPolygon();
	virtual IShape* OnCopy();
	virtual void SetData(TagShape& obj);
	virtual TagShape GetData();
	virtual int OnDraw(CDC *pDc);
	virtual BOOL IsSelect(UINT nFlags, CPoint point);
	virtual int OnButtonDown(UINT nFlags, CPoint point);
	virtual int OnButtonUp(UINT nFlags, CPoint point);
	virtual int OnMouseMove(UINT nFlags, CPoint point);
	virtual int OnMove(UINT nFlags, CPoint point);
	virtual void Serialize(CArchive& ar){}
// 	virtual IShape* operator =(TagShape& obj)
// 	{
// 		m_nNum = obj.m_nNum;
// 		m_pStartPos = NULL;
// 		m_ArrayPoints.Copy(obj.m_ArrayPoints);
// 		return this;
// 	}
protected:
	int m_nNum;
	CRgn *m_pStartPos;
	CArray<CPoint , CPoint> m_ArrayPoints;
};

#endif // !defined(AFX_POLYGON_H__48A9336B_6857_40D4_A2B1_20CCB480048A__INCLUDED_)
