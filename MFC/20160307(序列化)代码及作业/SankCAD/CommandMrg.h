// CommandMrg.h: interface for the CCommandMrg class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMMANDMRG_H__D05DC5E2_53FF_488C_BC85_BACF685099D3__INCLUDED_)
#define AFX_COMMANDMRG_H__D05DC5E2_53FF_488C_BC85_BACF685099D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxtempl.h>
#include "ICommand.h"


class CCommandMrg  
{
public:
	CCommandMrg();
	virtual ~CCommandMrg();
	ICommand *Undo();
	ICommand *Redo();
	void AddCommand(ICommand *p_Command);
protected:
	CList<ICommand *, ICommand *> m_UndoList;
	CList<ICommand *, ICommand *> m_RedoList;
};

#endif // !defined(AFX_COMMANDMRG_H__D05DC5E2_53FF_488C_BC85_BACF685099D3__INCLUDED_)
