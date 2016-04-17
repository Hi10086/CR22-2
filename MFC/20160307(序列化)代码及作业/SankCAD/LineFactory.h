// LineFactory.h: interface for the CLineFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINEFACTORY_H__69D80B5A_9AAF_4774_BDE8_DFE470E4B6D1__INCLUDED_)
#define AFX_LINEFACTORY_H__69D80B5A_9AAF_4774_BDE8_DFE470E4B6D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Line.h"
#include "IShapeFactory.h"

class CLineFactory : public IShapeFactory  
{
public:
	CLineFactory();
	virtual ~CLineFactory();
	virtual IShape *CreateShape();
};

#endif // !defined(AFX_LINEFACTORY_H__69D80B5A_9AAF_4774_BDE8_DFE470E4B6D1__INCLUDED_)
