#include "SmartPtr.h"


CSmartPtr::CSmartPtr()
{
	//m_obj = NULL;
	m_obj = NULL;
	cout << "CSmartPtr::CSmartPtr()" << endl;
}

CSmartPtr::CSmartPtr(CMyString * p)
{
	//m_obj = p;
	//m_obj = new CMyString(*p);
	m_obj = new CRefCounts(p);
	if (m_obj != NULL)
	{
		m_obj->AddRef();
	}

	cout << "CSmartPtr::CSmartPtr(CMyString * p)" << endl;
}

CSmartPtr::CSmartPtr(CSmartPtr & obj)
{
	m_obj = obj.m_obj;
	if (m_obj != NULL)
	{
		m_obj->AddRef();
	}

	cout << "CSmartPtr::CSmartPtr(CSmartPtr & obj)" << endl;
}

CSmartPtr::~CSmartPtr()
{
	if (m_obj != NULL)
	{
		m_obj->Release();
	}
	cout << "CSmartPtr::~CSmartPtr()" << endl;
}

CMyString * CSmartPtr::operator->()
{
	return m_obj->m_obj;
}

CSmartPtr CSmartPtr::operator+(const CSmartPtr & obj)
{
	CSmartPtr ret = new CMyString(*m_obj->m_obj);
	*(ret.m_obj->m_obj) += *(obj.m_obj->m_obj);
	return ret;
}

CSmartPtr CSmartPtr::operator+(const char * s)
{
	CSmartPtr ret = new CMyString(*m_obj->m_obj);
	*(ret.m_obj->m_obj) += s;
	return ret;
}

CSmartPtr & CSmartPtr::operator=(const CSmartPtr & obj)
{
	if (m_obj == obj.m_obj)
	{
		return *this;
	}
	if (m_obj != NULL)
	{
		m_obj->Release();
	}

	m_obj = obj.m_obj;
	if (m_obj != NULL)
	{
		m_obj->AddRef();
	}

	return *this;
}

CMyString CSmartPtr::operator*()
{
	return *m_obj->m_obj;
}

