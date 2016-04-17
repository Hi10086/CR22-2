// MyString.h: interface for the CMyString class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSTRING_H__AA03754F_03BD_4F0D_85B9_24DE5DB53C34__INCLUDED_)
#define AFX_MYSTRING_H__AA03754F_03BD_4F0D_85B9_24DE5DB53C34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <stdio.h>
#include <string.h>
/*#include <iostream>*/
#include <locale>

class CMyString
{
public:
	CMyString();
	CMyString(const char *s);
	CMyString(const CMyString& obj);
	
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

private:
	CMyString& SetString_Deep(const char *s);
	CMyString& SetString_Deep(const CMyString& obj);
	int IsEmpty();
	void Init();
	void Fnit();
	int Compare(const char *s) const;
	int Compare(const CMyString& obj) const;
	char *AllocBuff(int size);
	inline bool IsNULL(const char *s) 
	{
		if (s == NULL)
		{
			return true;
		}
		return false;
	}
private:
	char *m_Buff;
	int m_Size;
	int m_Length;
};



#endif // !defined(AFX_MYSTRING_H__AA03754F_03BD_4F0D_85B9_24DE5DB53C34__INCLUDED_)
