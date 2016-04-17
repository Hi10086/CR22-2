// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__4FF886BA_84D6_4AAF_A11C_FF3AFE19495E__INCLUDED_)
#define AFX_LINE_H__4FF886BA_84D6_4AAF_A11C_FF3AFE19495E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Shape.h"

class CLine : public CShape  
{
public:
	CLine();
	virtual ~CLine();
	virtual void OnDraw(CDC *pDc);
	virtual int OnButtonDown(UINT nFlags, CPoint point);
	virtual int OnButtonUp(UINT nFlags, CPoint point);
	virtual int OnMouseMove(UINT nFlags, CPoint point);
protected:
	CPoint m_Start;
	CPoint m_End;
};

#endif // !defined(AFX_LINE_H__4FF886BA_84D6_4AAF_A11C_FF3AFE19495E__INCLUDED_)
