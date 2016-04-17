// PolyFactory.h: interface for the CPolyFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POLYFACTORY_H__14BA06E1_ECEF_4141_B468_F57F519FBDF2__INCLUDED_)
#define AFX_POLYFACTORY_H__14BA06E1_ECEF_4141_B468_F57F519FBDF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IShapeFactory.h"
#include "Polygon.h"

class __declspec(dllexport) CPolyFactory : public IShapeFactory  
{
public:
	CPolyFactory();
	virtual ~CPolyFactory();
	virtual IShape *CreateShape();
};

#endif // !defined(AFX_POLYFACTORY_H__14BA06E1_ECEF_4141_B468_F57F519FBDF2__INCLUDED_)
