#include "RefCount.h"




CRefCount::CRefCount(CMyString *obj)
{
	m_string = obj;
	m_ref_counts = new int(1);
}

CRefCount::CRefCount(CRefCount & obj)
{
	m_string = obj.m_string;
	m_ref_counts = obj.m_ref_counts;
	(*m_ref_counts)++;
}

CRefCount::~CRefCount()
{
	if (--(*m_ref_counts) == 0)
	{
		delete m_ref_counts;
		delete m_string;
	}
	m_ref_counts = NULL;
	m_string = NULL;
}
