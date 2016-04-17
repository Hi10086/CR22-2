// ICommand.h: interface for the ICommand class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICOMMAND_H__F6AE6614_707E_4202_9999_152610023EEC__INCLUDED_)
#define AFX_ICOMMAND_H__F6AE6614_707E_4202_9999_152610023EEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ICommand  
{
public:
	ICommand();
	virtual ~ICommand();
  virtual void Undo() = 0;
  virtual void Redo() = 0;
};

#endif // !defined(AFX_ICOMMAND_H__F6AE6614_707E_4202_9999_152610023EEC__INCLUDED_)
