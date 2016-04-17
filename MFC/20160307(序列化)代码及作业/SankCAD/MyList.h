// MyList.h: interface for the CMyList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYLIST_H__CB9ED7B6_4458_42BC_A8D1_CBD4F1572E16__INCLUDED_)
#define AFX_MYLIST_H__CB9ED7B6_4458_42BC_A8D1_CBD4F1572E16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxtempl.h>

template<typename T, typename ARG>
class CMyList : public CList<T, ARG>  
{
public:
	CMyList(){}
	virtual ~CMyList()
	{
		POSITION pos = GetHeadPosition();
		while (pos)
		{
			IShape *pShape = GetNext(pos);
			delete pShape;
		}
	}
};

#endif // !defined(AFX_MYLIST_H__CB9ED7B6_4458_42BC_A8D1_CBD4F1572E16__INCLUDED_)
