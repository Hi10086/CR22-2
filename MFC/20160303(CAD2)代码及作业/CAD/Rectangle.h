// Rectangle.h: interface for the CRectangle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECTANGLE_H__C83EB36B_EE6F_4B4F_9DED_01E556BA0496__INCLUDED_)
#define AFX_RECTANGLE_H__C83EB36B_EE6F_4B4F_9DED_01E556BA0496__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "IShape.h"

class CRectangle  :public IShape
{
public:
	CRectangle();
	virtual ~CRectangle();
  virtual void OnDraw(CDC *pDC);
  virtual void OnLButtonDown(UINT nFlags, CPoint point);
  virtual void OnLButtonUp(UINT nFlags, CPoint point);
  virtual void OnMouseMove(UINT nFlags, CPoint point);
  virtual void SetPen(CMyPen pen);
  virtual BOOL IsSelect(CPoint pt);
  virtual void OnDrawSelect(CDC *pDC);
  virtual CMyPen GetPen()
  {
    return m_pen;
  }
private:
  CPoint m_ptBegin;
  CPoint m_ptEnd;
  CMyPen m_pen;
};

class CRectangleFactory :public IMyClassFactory
{
public:
  CRectangleFactory() {}
  virtual ~CRectangleFactory() {}
  virtual IShape* CreateObject()
  {
    return new CRectangle();
  }
};

#endif // !defined(AFX_RECTANGLE_H__C83EB36B_EE6F_4B4F_9DED_01E556BA0496__INCLUDED_)
