#pragma once
#include "MyString.h"

class CRefCount
{
public:
	CRefCount(CMyString *obj);
	CRefCount(CRefCount & obj);
	~CRefCount();

public:
	CMyString *m_string;
private:
	int *m_ref_counts;
};

