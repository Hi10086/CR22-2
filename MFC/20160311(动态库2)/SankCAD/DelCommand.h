// DelCommand.h: interface for the DelCommand class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DELCOMMAND_H__50174902_6E54_4424_BBE4_6F46C9D10A79__INCLUDED_)
#define AFX_DELCOMMAND_H__50174902_6E54_4424_BBE4_6F46C9D10A79__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxtempl.h>
#include "IShape.h"
#include "ICommand.h"

class __declspec(dllexport) DelCommand : public ICommand  
{
public:
	DelCommand(IShape *pShape, CList<IShape *, IShape *> *pShapeList);
	virtual ~DelCommand();
	virtual void Redo();
	virtual void Undo();
protected:
	IShape *m_pShape;
	CList<IShape *, IShape *>* m_pShapeList;
};

#endif // !defined(AFX_DELCOMMAND_H__50174902_6E54_4424_BBE4_6F46C9D10A79__INCLUDED_)
