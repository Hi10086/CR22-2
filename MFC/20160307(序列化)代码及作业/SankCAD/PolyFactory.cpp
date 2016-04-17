// PolyFactory.cpp: implementation of the CPolyFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SankCAD.h"
#include "PolyFactory.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPolyFactory::CPolyFactory()
{

}

CPolyFactory::~CPolyFactory()
{

}

IShape *CPolyFactory::CreateShape()
{
	return new CPolygon();
}