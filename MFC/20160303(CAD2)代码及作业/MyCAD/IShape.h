// IShape.h: interface for the IShape class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ISHAPE_H__6C6782A8_F494_401E_9F26_3EACE32D2D44__INCLUDED_)
#define AFX_ISHAPE_H__6C6782A8_F494_401E_9F26_3EACE32D2D44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct CMyPen
{
  CMyPen()
  {
    m_nPenStyle = PS_SOLID;
    m_nWidth = 1;
    m_crColor = 0;
  }

  int m_nPenStyle; 
  int m_nWidth; 
  COLORREF m_crColor;
};

class IShape  
{
public:
	IShape();
	virtual ~IShape();
	virtual void OnDraw(CDC *pDC) = 0;
	virtual void OnLButtonDown(UINT nFlags, CPoint point) = 0;
	virtual void OnLButtonUp(UINT nFlags, CPoint point) = 0;
	
	virtual void OnMouseMove(UINT nFlags, CPoint point) = 0;
    virtual void ShapeMove(UINT nFlags, CPoint point) = 0;
	virtual void SetPen(CMyPen pen) = 0;
	virtual CMyPen GetPen() = 0;
	virtual BOOL IsSelect(CPoint pt) = 0;
	virtual void OnDrawSelect(CDC *pDC) = 0;
	virtual IShape* OnCopy() = 0;
};

//¿‡π§≥ß
class IMyClassFactory
{
public:
  IMyClassFactory() {}
  virtual ~IMyClassFactory() {}
  virtual IShape* CreateObject() = 0;
};


#endif // !defined(AFX_ISHAPE_H__6C6782A8_F494_401E_9F26_3EACE32D2D44__INCLUDED_)
