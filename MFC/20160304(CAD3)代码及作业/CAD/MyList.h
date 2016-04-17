// MyList.h: interface for the CMyList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYLIST_H__12477D38_BDEE_48AE_8E6E_1A64C07017CE__INCLUDED_)
#define AFX_MYLIST_H__12477D38_BDEE_48AE_8E6E_1A64C07017CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>

template<typename TYPE, typename ARG>
class CMyList : public CList<TYPE, ARG>  
{
public:
  CMyList() {}
	virtual ~CMyList()
  {
    POSITION pos  = GetHeadPosition();
    while(pos)
    {
      IShape *pShape = GetNext(pos);
      delete pShape;
    }
  }

};

#endif // !defined(AFX_MYLIST_H__12477D38_BDEE_48AE_8E6E_1A64C07017CE__INCLUDED_)
