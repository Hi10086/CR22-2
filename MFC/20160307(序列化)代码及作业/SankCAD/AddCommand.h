// AddCommand.h: interface for the AddCommand class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADDCOMMAND_H__8FFA12B0_854B_4B78_B1FA_7F27CD79469A__INCLUDED_)
#define AFX_ADDCOMMAND_H__8FFA12B0_854B_4B78_B1FA_7F27CD79469A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ICommand.h"
#include <afxtempl.h>
#include "IShape.h"

class AddCommand : public ICommand  
{
public:
	AddCommand(IShape *pShape, CList<IShape *, IShape *>* pShapeList);
	virtual ~AddCommand();
	virtual void Redo();
	virtual void Undo();
protected:
	IShape *m_pShape;
	CList<IShape *, IShape *>* m_pShapeList;
};

#endif // !defined(AFX_ADDCOMMAND_H__8FFA12B0_854B_4B78_B1FA_7F27CD79469A__INCLUDED_)
