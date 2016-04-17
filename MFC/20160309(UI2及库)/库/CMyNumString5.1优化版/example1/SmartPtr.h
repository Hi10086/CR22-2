#pragma once
#include "RefCounts.h"
#include "MyString.h"
using namespace std;

class CSmartPtr
{
public:
	CSmartPtr();
	CSmartPtr(CMyString *p);
	CSmartPtr(CSmartPtr& obj);
	~CSmartPtr();
	CMyString *operator->();
	CSmartPtr operator+(const CSmartPtr& obj);
	CSmartPtr operator+(const char *s);
	CSmartPtr& operator=(const CSmartPtr& obj);
	CMyString operator*();
private:
	//CMyString *m_obj;
	CRefCounts *m_obj;
};

