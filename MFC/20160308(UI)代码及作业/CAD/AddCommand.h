// AddCommand.h: interface for the CAddCommand class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADDCOMMAND_H__DA5523E5_9348_407D_A1CA_62056008593C__INCLUDED_)
#define AFX_ADDCOMMAND_H__DA5523E5_9348_407D_A1CA_62056008593C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ICommand.h"
#include "MyList.h"
#include "IShape.h"

class CAddCommand : public ICommand  
{
public:
	CAddCommand(IShape *pShape, CMyList<IShape*, IShape*>& Shapes)
    :m_Shapes(Shapes), m_pShape(pShape)
  {

  }
	virtual ~CAddCommand()
  {
    
  }
  virtual void Undo()
  {
    m_Shapes.RemoveAt(m_Shapes.Find(m_pShape));
  }
  virtual void Redo()
  {
    m_Shapes.AddTail(m_pShape);
  }
private:
  IShape *m_pShape;
  CMyList<IShape*, IShape*>& m_Shapes;
};

#endif // !defined(AFX_ADDCOMMAND_H__DA5523E5_9348_407D_A1CA_62056008593C__INCLUDED_)
