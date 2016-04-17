// AddCommand.cpp: implementation of the AddCommand class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SankCAD.h"
#include "AddCommand.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AddCommand::AddCommand(IShape *pShape, CList<IShape *, IShape *>* pShapeList)
	:m_pShape(pShape), m_pShapeList(pShapeList)
{

}

AddCommand::~AddCommand()
{
	if (m_pShape != NULL)
	{
		delete m_pShape;
	}
}

void AddCommand::Redo()
{
	m_pShapeList->AddTail(m_pShape);
}

void AddCommand::Undo()
{
	POSITION pos = m_pShapeList->Find(m_pShape);
	m_pShapeList->RemoveAt(pos);
}
