// Shape.h: interface for the CShape class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHAPE_H__8A3DCF14_1201_4280_A65D_6BBCB7BE512E__INCLUDED_)
#define AFX_SHAPE_H__8A3DCF14_1201_4280_A65D_6BBCB7BE512E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CShape  
{
public:
	CShape();
	virtual ~CShape();
	virtual void OnDraw(CDC *pDc) = 0;
	virtual int OnButtonDown(UINT nFlags, CPoint point) = 0;
	virtual int OnButtonUp(UINT nFlags, CPoint point) = 0;
	virtual int OnMouseMove(UINT nFlags, CPoint point) = 0;
};

#endif // !defined(AFX_SHAPE_H__8A3DCF14_1201_4280_A65D_6BBCB7BE512E__INCLUDED_)
