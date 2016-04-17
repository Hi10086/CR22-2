#include "MyNumString.h"



CMyNumString::CMyNumString()
{
}

CMyNumString::CMyNumString(const char * s)
{
	if (IsNumString(s))
	{
		CMyString::MyCpy(s);
	}
}

CMyNumString::CMyNumString(CMyNumString & obj)
{
	CMyString::MyCpy(obj);
}


CMyNumString & CMyNumString::MyCat(const char * s)
{
	if (IsNumString(s))
	{
		int new_num = atoi(CMyString::GetString()) + atoi(s);

		int old_length = CMyString::GetLength();
		int new_length = strlen(s);
		if (new_length < old_length)
		{
			new_length = old_length;
		}

		char *new_s = new char[new_length + 2];
		if (new_s != NULL)
		{
			*new_s = '\0';
			sprintf(new_s, "%d", new_num);
			CMyString::MyCpy(new_s);
			delete[] new_s;
		}
	}

	return *this;
}

CMyNumString::~CMyNumString()
{
}

bool CMyNumString::IsNumString(const char * s)
{
	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
		{
			return false;
		}

		s++;
	}

	return true;
}
