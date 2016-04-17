#include "RefCounts.h"




CRefCounts::CRefCounts(CMyString * obj)
{
	m_ref_counts = 0;
	m_obj = obj;
}

CRefCounts::~CRefCounts()
{
}

int CRefCounts::AddRef()
{
	return ++m_ref_counts;
}

int CRefCounts::Release()
{
	if (--m_ref_counts == 0)
	{
		delete m_obj;
		//delete this;
	}

	return m_ref_counts;
}
