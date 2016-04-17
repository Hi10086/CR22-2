#pragma once
#include "MyString.h"

class CMyNumString :
	public CMyString
{
public:
	CMyNumString();
	CMyNumString(const char *s);
	CMyNumString(CMyNumString& obj);
	// 这个构成了基类的虚函数吗？还是说他顶掉了基类的同名函数
	virtual CMyNumString& MyCat(const char *s);
	virtual ~CMyNumString();
private:
	bool IsNumString(const char *s);
};

