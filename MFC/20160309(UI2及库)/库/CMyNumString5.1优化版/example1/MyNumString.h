#pragma once
#include "MyString.h"

class CMyNumString :
	public CMyString
{
public:
	CMyNumString();
	CMyNumString(const char *s);
	CMyNumString(CMyNumString& obj);
	// ��������˻�����麯���𣿻���˵�������˻����ͬ������
	virtual CMyNumString& MyCat(const char *s);
	virtual ~CMyNumString();
private:
	bool IsNumString(const char *s);
};

