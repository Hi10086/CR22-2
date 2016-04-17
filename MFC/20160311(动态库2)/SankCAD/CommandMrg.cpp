// CommandMrg.cpp: implementation of the CCommandMrg class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SankCAD.h"
#include "CommandMrg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCommandMrg::CCommandMrg()
{
	
}

CCommandMrg::~CCommandMrg()
{

}

ICommand *CCommandMrg::Undo()
{
	if (m_UndoList.IsEmpty())
	{
		return NULL;
	}

	ICommand *pCommand = m_UndoList.GetHead();
	pCommand->Undo();
	m_UndoList.RemoveHead();
	m_RedoList.AddHead(pCommand);
	return pCommand;
}

ICommand *CCommandMrg::Redo()
{
	if (m_RedoList.IsEmpty())
	{
		return NULL;
	}
	
	ICommand *pCommand = m_RedoList.GetHead();
	pCommand->Redo();
	m_RedoList.RemoveHead();
	m_UndoList.AddHead(pCommand);
	
	return pCommand;
}
void CCommandMrg::AddCommand(ICommand *p_Command)
{
	m_UndoList.AddHead(p_Command);
	POSITION pos = m_RedoList.GetHeadPosition();
	while (pos)
	{
		ICommand *pCom = m_RedoList.GetNext(pos);
		delete pCom;
	}
	m_RedoList.RemoveAll();
}
