// MoveCommand.h: interface for the MoveCommand class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOVECOMMAND_H__5BF2519F_170D_49FC_9AB4_E2043ABF1DD8__INCLUDED_)
#define AFX_MOVECOMMAND_H__5BF2519F_170D_49FC_9AB4_E2043ABF1DD8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CommandMrg.h"
#include "IShape.h"

class __declspec(dllexport) MoveCommand : public ICommand  
{
public:
	MoveCommand(IShape *pShape, TagShape& data,CList<IShape *, IShape *>* pList);
	virtual ~MoveCommand();
	virtual void Redo();
	virtual void Undo();
protected:
	TagShape m_OldData;
	TagShape m_NewData;
	IShape *m_pShape;
	CList<IShape *, IShape *>* m_pShapeList;
};

#endif // !defined(AFX_MOVECOMMAND_H__5BF2519F_170D_49FC_9AB4_E2043ABF1DD8__INCLUDED_)
