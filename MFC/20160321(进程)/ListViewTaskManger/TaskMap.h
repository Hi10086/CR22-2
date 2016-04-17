// TaskMap.h: interface for the CTaskMap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TASKMAP_H__51BC8967_D8BA_4200_BB7A_BC08AD318E89__INCLUDED_)
#define AFX_TASKMAP_H__51BC8967_D8BA_4200_BB7A_BC08AD318E89__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <WINDOWS.H>
#include "TaskInfo.h"
#include <MAP>

template<typename Key, typename T>
class CTaskMap : public std::map<Key, T> 
{
public:
	CTaskMap(){}
	virtual ~CTaskMap(){}
};

#endif // !defined(AFX_TASKMAP_H__51BC8967_D8BA_4200_BB7A_BC08AD318E89__INCLUDED_)
