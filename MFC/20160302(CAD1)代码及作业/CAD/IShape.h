// IShape.h: interface for the IShape class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ISHAPE_H__6C6782A8_F494_401E_9F26_3EACE32D2D44__INCLUDED_)
#define AFX_ISHAPE_H__6C6782A8_F494_401E_9F26_3EACE32D2D44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class IShape  
{
public:
	IShape();
	virtual ~IShape();
  virtual void OnDraw(CDC *pDC) = 0;
  virtual void OnLButtonDown(UINT nFlags, CPoint point) = 0;
  virtual void OnLButtonUp(UINT nFlags, CPoint point) = 0;
  virtual void OnMouseMove(UINT nFlags, CPoint point) = 0;
};


#endif // !defined(AFX_ISHAPE_H__6C6782A8_F494_401E_9F26_3EACE32D2D44__INCLUDED_)
