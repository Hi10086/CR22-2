// LineFactory.cpp: implementation of the CLineFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SankCAD.h"
#include "LineFactory.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLineFactory::CLineFactory()
{

}

CLineFactory::~CLineFactory()
{

}

IShape *CLineFactory::CreateShape()
{
	return new CLine();
}
