// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__7C5DF8DC_C8ED_4031_9C1A_88F10F4E8711__INCLUDED_)
#define AFX_LINE_H__7C5DF8DC_C8ED_4031_9C1A_88F10F4E8711__INCLUDED_

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
	virtual IShape* OnCopy();
	virtual TagShape GetData();	
	virtual void SetData(TagShape& obj);
	virtual int OnDraw(CDC *pDc);
	virtual BOOL IsSelect(UINT nFlags, CPoint point);
	virtual int OnButtonDown(UINT nFlags, CPoint point);
	virtual int OnButtonUp(UINT nFlags, CPoint point);
	virtual int OnMouseMove(UINT nFlags, CPoint point);
	virtual int OnMove(UINT nFlags, CPoint point);
	virtual void Serialize(CArchive& ar);
// 	virtual IShape* operator=(TagShape& obj)
// 	{
// 		m_StartPos = obj.m_StartPos;
// 		m_MovePos = obj.m_MovePos;
// 		m_EndPos = obj.m_EndPos;
// 		return this;
// 	}
protected:
	CPoint m_StartPos;
	CPoint m_EndPos;
	CPoint m_MovePos;
};

#endif // !defined(AFX_LINE_H__7C5DF8DC_C8ED_4031_9C1A_88F10F4E8711__INCLUDED_)
