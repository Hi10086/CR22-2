#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
//#include "RefCounts.h"


class CMyString
{
public:
	CMyString();
	CMyString(const char *s);
	CMyString(const CMyString& obj);

	// 深拷贝
	//virtual CMyString& MyCpy(const char *s);
	//virtual CMyString& MyCat(const char *s);
	//virtual CMyString& MyCat(const CMyString& obj);

	// 浅拷贝
	//virtual CMyString& MyCpy(const CMyString& obj);

	const char *GetString() const;
	int GetLength() const;
	virtual ~CMyString();

	virtual CMyString operator+(const char *s);
	virtual CMyString operator+(const CMyString& obj);
	friend CMyString operator+(const char *s, const CMyString& obj);
	virtual CMyString operator+=(const char *s);
	virtual CMyString operator+=(const CMyString& obj);
	virtual CMyString& operator=(const char *s);
	virtual CMyString& operator=(const CMyString& obj);
	virtual bool operator==(const char *s) const;
	virtual bool operator==(const CMyString& obj) const;
	virtual bool operator!=(const char *s) const;
	virtual bool operator!=(const CMyString& obj) const;
	virtual bool operator>(const char *s) const;
	virtual bool operator>(const CMyString& obj) const;
	virtual bool operator<(const char *s) const;
	virtual bool operator<(const CMyString& obj) const;
	virtual const char *operator[](int index) const;
	virtual operator const char *();
private:
	CMyString& SetString_Deep(const char *s);
	CMyString& SetString_Deep(const CMyString& obj);
	//CMyString& SetString_Shallow(const CMyString& obj);
	int IsEmpty();
	void Init();
	void Fnit();
	int Compare(const char *s) const;
	int Compare(const CMyString& obj) const;
	//void CreateRef();
	char *AllocBuff(int size);
private:
	char *m_Buff;
	int m_Size;
	int m_Length;

	// 引用计数
	//int *m_ref_counts;
};

