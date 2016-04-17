// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__1852604A_BB40_4BDE_9636_8AD56ED0E765__INCLUDED_)
#define AFX_LINE_H__1852604A_BB40_4BDE_9636_8AD56ED0E765__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IShape.h"

class CLine : public IShape  
{
public:
	CLine();
	virtual ~CLine();
  virtual void OnDraw(CDC *pDC);
  virtual void OnLButtonDown(UINT nFlags, CPoint point);
  virtual void OnLButtonUp(UINT nFlags, CPoint point);
  virtual void OnMouseMove(UINT nFlags, CPoint point);
private:
  CPoint m_ptBegin;
  CPoint m_ptEnd;
};

#endif // !defined(AFX_LINE_H__1852604A_BB40_4BDE_9636_8AD56ED0E765__INCLUDED_)
