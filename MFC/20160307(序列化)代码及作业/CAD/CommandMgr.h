// CommandMgr.h: interface for the CCommandMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMMANDMGR_H__A69CABBB_325B_4D1F_8CC0_E950E11DC667__INCLUDED_)
#define AFX_COMMANDMGR_H__A69CABBB_325B_4D1F_8CC0_E950E11DC667__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ICommand.h"
#include <afxtempl.h>

class CCommandMgr  
{
public:
	CCommandMgr();
	virtual ~CCommandMgr();

  void Undo()
  {
    //����
    if (!m_UndoList.IsEmpty())
    {
      ICommand *pCommand = m_UndoList.GetTail();
      
      pCommand->Undo();

      //�ƶ���־����������
      m_RedoList.AddTail(pCommand);
      m_UndoList.RemoveTail();
    }
  }

  void Redo()
  {
    //����
    if (!m_RedoList.IsEmpty())
    {
      ICommand *pCommand = m_RedoList.GetTail();
      
      pCommand->Redo();

      //�ƶ���־����������
      m_UndoList.AddTail(pCommand);
      m_RedoList.RemoveTail();
    }
  }

  void InsertCommand(ICommand* pCommand)
  {
    m_UndoList.AddTail(pCommand);
    m_RedoList.RemoveAll();
  }
private:
  CList<ICommand*, ICommand*> m_UndoList;
  CList<ICommand*, ICommand*> m_RedoList;
};

#endif // !defined(AFX_COMMANDMGR_H__A69CABBB_325B_4D1F_8CC0_E950E11DC667__INCLUDED_)
