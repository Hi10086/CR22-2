// DelCommand.cpp: implementation of the DelCommand class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SankCAD.h"
#include "DelCommand.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DelCommand::DelCommand(IShape *pShape, CList<IShape *, IShape *> *pShapeList)
{
	m_pShape = pShape;
	m_pShapeList = pShapeList;
}

DelCommand::~DelCommand()
{
// 	if (m_pShape != NULL)
// 	{
// 		delete m_pShape;
// 	}
}

void DelCommand::Redo()
{
	POSITION pos = m_pShapeList->Find(m_pShape);
	m_pShapeList->RemoveAt(pos);
}

void DelCommand::Undo()
{
	m_pShapeList->AddTail(m_pShape);	
}
