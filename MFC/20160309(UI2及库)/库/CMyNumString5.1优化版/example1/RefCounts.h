#pragma once
#include <stdio.h>
#include "MyString.h"

class CRefCounts
{
public:
	CRefCounts(CMyString *obj = NULL);
	virtual ~CRefCounts();
	virtual int AddRef();
	virtual int Release();
	friend class CSmartPtr;
private:
	int m_ref_counts;
	CMyString *m_obj;
};

