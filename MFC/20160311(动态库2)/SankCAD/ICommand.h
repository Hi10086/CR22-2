// ICommand.h: interface for the ICommand class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICOMMAND_H__5084393C_0BDC_4E61_9EF5_A85DCD3CA2FB__INCLUDED_)
#define AFX_ICOMMAND_H__5084393C_0BDC_4E61_9EF5_A85DCD3CA2FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class __declspec(dllexport) ICommand  
{
public:
	ICommand();
	virtual ~ICommand();
	virtual void Undo() = 0;
	virtual void Redo() = 0;
};

#endif // !defined(AFX_ICOMMAND_H__5084393C_0BDC_4E61_9EF5_A85DCD3CA2FB__INCLUDED_)
