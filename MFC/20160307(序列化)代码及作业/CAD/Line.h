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
  DECLARE_SERIAL(CLine)
public:
	CLine();
	virtual ~CLine();
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

  virtual void Serialize(CArchive& ar)
  {
    //判断保存还是读取
    if (ar.IsStoring())
    {
      ar << m_ptBegin
         << m_ptEnd
         << m_pen.m_crColor
         << m_pen.m_nPenStyle
         << m_pen.m_nWidth;
    }
    else
    {
     ar >> m_ptBegin
        >> m_ptEnd
        >> m_pen.m_crColor
        >> m_pen.m_nPenStyle
        >> m_pen.m_nWidth;
    }
  }
private:
  CPoint m_ptBegin;
  CPoint m_ptEnd;
  CMyPen m_pen;
};

class CLineFactory :public IMyClassFactory
{
public:
  CLineFactory() {}
  virtual ~CLineFactory() {}
  virtual IShape* CreateObject()
  {
    return new CLine();
  }
};

#endif // !defined(AFX_LINE_H__1852604A_BB40_4BDE_9636_8AD56ED0E765__INCLUDED_)
