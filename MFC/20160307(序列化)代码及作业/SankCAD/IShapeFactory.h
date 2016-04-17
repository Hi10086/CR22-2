// IShapeFactory.h: interface for the IShapeFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ISHAPEFACTORY_H__43F65DEB_D4A0_434E_A3CB_67DEF3F417A1__INCLUDED_)
#define AFX_ISHAPEFACTORY_H__43F65DEB_D4A0_434E_A3CB_67DEF3F417A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "IShape.h"

class IShapeFactory  
{
public:
	IShapeFactory();
	virtual ~IShapeFactory();
	virtual IShape *CreateShape() = 0;
};

#endif // !defined(AFX_ISHAPEFACTORY_H__43F65DEB_D4A0_434E_A3CB_67DEF3F417A1__INCLUDED_)
