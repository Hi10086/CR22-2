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

  void Serialize(CArchive& ar)
  {
    if (ar.IsStoring())
    {
      //写入个数
      int nCount = GetCount();
      ar.Write(&nCount, sizeof(nCount));

      POSITION pos = GetHeadPosition();
      while(pos)
      {
        CObject *pObject = GetNext(pos);
        ar << pObject;
      }
    }
    else
    {
      //获取数量
      int nCount;
      ar.Read(&nCount, sizeof(nCount));
      CObject *pObject = NULL;
      for (int i = 0; i < nCount; i++)
      {
        ar >> pObject;
        AddTail((IShape*)pObject);
      }
	  }
  }
};

#endif // !defined(AFX_MYLIST_H__12477D38_BDEE_48AE_8E6E_1A64C07017CE__INCLUDED_)
