// MoveCommand.cpp: implementation of the MoveCommand class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SankCAD.h"
#include "MoveCommand.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MoveCommand::MoveCommand(IShape *pShape, TagShape& OldData,CList<IShape *, IShape *>* pList)
{
	m_OldData = OldData;
	m_NewData = pShape->GetData();
	m_pShape = pShape;
	m_pShapeList = pList;
}

MoveCommand::~MoveCommand()
{

}

void MoveCommand::Undo()
{
	POSITION pos = m_pShapeList->Find(m_pShape);
	if (pos)
	{
		m_pShape->SetData(m_OldData);
	}
}

void MoveCommand::Redo()
{
	POSITION pos = m_pShapeList->Find(m_pShape);
	if (pos)
	{
		m_pShape->SetData(m_NewData);
	}
}

