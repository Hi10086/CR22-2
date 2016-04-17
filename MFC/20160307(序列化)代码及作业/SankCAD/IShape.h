// IShape.h: interface for the IShape class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ISHAPE_H__EBB90E46_507A_46CD_92C9_C0F6B9CE66B7__INCLUDED_)
#define AFX_ISHAPE_H__EBB90E46_507A_46CD_92C9_C0F6B9CE66B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxwin.h>
#include <afxtempl.h>

class TagShape
{
public:
	TagShape(){}
	TagShape(TagShape& obj)
	{
		m_StartPos = obj.m_StartPos;
		m_EndPos = obj.m_EndPos;
		m_MovePos = obj.m_MovePos;
		m_nNum = obj.m_nNum;
		m_pStartPos = obj.m_pStartPos;
		m_ArrayPoints.Copy(obj.m_ArrayPoints);
	}
	TagShape& operator= (TagShape& obj)
	{
		m_StartPos = obj.m_StartPos;
		m_EndPos = obj.m_EndPos;
		m_MovePos = obj.m_MovePos;
		m_nNum = obj.m_nNum;
		m_pStartPos = obj.m_pStartPos;
		m_ArrayPoints.Copy(obj.m_ArrayPoints);
		return *this;
	}

	CPoint m_StartPos;
	CPoint m_EndPos;
	CPoint m_MovePos;
	int m_nNum;
	CRgn *m_pStartPos;
	CArray<CPoint , CPoint> m_ArrayPoints;
};

class IShape :public CObject 
{
public:
	IShape();
	virtual ~IShape();
	virtual IShape* OnCopy() = 0;
	virtual TagShape GetData() = 0;
	virtual void SetData(TagShape& obj) = 0;
	virtual int OnDraw(CDC *pDc) = 0;
	virtual BOOL IsSelect(UINT nFlags, CPoint point) = 0;
	virtual int OnButtonDown(UINT nFlags, CPoint point) = 0;
	virtual int OnButtonUp(UINT nFlags, CPoint point) = 0;
	virtual int OnMouseMove(UINT nFlags, CPoint point) = 0;
	virtual int OnMove(UINT nFlags, CPoint point) = 0;
};

#endif // !defined(AFX_ISHAPE_H__EBB90E46_507A_46CD_92C9_C0F6B9CE66B7__INCLUDED_)
