#include "MyString.h"
using namespace std;

CMyString::CMyString()
{
	Init();	
	//cout << "CMyString::CMyString()" << endl;
}

CMyString::CMyString(const char *s)
{
	Init();
	SetString_Deep(s);
	//cout << "CMyString::CMyString(const char *s)" << endl;
}

CMyString::CMyString(const CMyString& obj)
{
	Init();
	SetString_Deep(obj.m_Buff);
	//cout << "CMyString::CMyString(const CMyString& obj)" << endl;
}

CMyString CMyString::operator+(const char * s)
{
	CMyString ret(*this);
	if (!IsNULL(s))
	{
		ret.SetString_Deep(s);
	}
	return ret;
}

CMyString CMyString::operator+(const CMyString & obj)
{
	CMyString ret(*this);
	ret.SetString_Deep(obj);
	return ret;
}

CMyString CMyString::operator+=(const char * s)
{
	if (!IsNULL(s)) 
	{
		SetString_Deep(s);
	}
	return *this;
}

CMyString CMyString::operator+=(const CMyString & obj)
{
	SetString_Deep(obj);
	return *this;
}

CMyString & CMyString::operator=(const char * s)
{
	Fnit();
	if (!IsNULL(s))
	{
		SetString_Deep(s);
	}
	return *this;
}

CMyString & CMyString::operator=(const CMyString & obj)
{
	Fnit();
	SetString_Deep(obj);
	return *this;
}

bool CMyString::operator==(const char * s) const
{
	if (Compare(s) == 0)
	{
		return true;
	}
	return false;
}

bool CMyString::operator==(const CMyString & obj) const
{
	if (Compare(obj) == 0)
	{
		return true;
	}
	return false;
}

bool CMyString::operator!=(const char * s) const
{
	if (Compare(s) != 0)
	{
		return true;
	}
	return false;
}

bool CMyString::operator!=(const CMyString & obj) const
{
	if (Compare(obj) != 0)
	{
		return true;
	}
	return false;
}

bool CMyString::operator>(const char * s) const
{
	if (Compare(s) > 0)
	{
		return true;
	}
	return false;
}

bool CMyString::operator>(const CMyString & obj) const
{
	if (Compare(obj) > 0)
	{
		return true;
	}
	return false;
}

bool CMyString::operator<(const char * s) const
{
	if (Compare(s) < 0)
	{
		return true;
	}
	return false;
}

bool CMyString::operator<(const CMyString & obj) const
{
	if (Compare(obj) < 0)
	{
		return true;
	}
	return false;
}

const char * CMyString::operator[](int index) const
{
	const char *ret = &m_Buff[index];
	return ret;
}

const char * CMyString::GetString() const
{
	return m_Buff;
}

int CMyString::GetLength() const
{
	return m_Length;
}

CMyString::~CMyString()
{
	Fnit();
	//cout << "CMyString::~CMyString()" << endl;
}

CMyString& CMyString::SetString_Deep(const char *s)
{
	if (s == NULL)
	{
		return *this;
	}

	int s_len = 0;
	char *new_buf = NULL;
	int new_buf_size = 0;

	s_len = ::strlen(s);
	new_buf_size = s_len + m_Length + 1;

	// 或者新内容大于旧数据，先new,拷贝旧数据，再深释放
	if (new_buf_size > m_Size)
	{
		new_buf = AllocBuff(new_buf_size);
		if (new_buf != NULL)
		{
			if (m_Buff != NULL)
			{
				// 先拷贝原来的
				strcpy(new_buf, m_Buff);
			}
		}
		
		Fnit();
		m_Buff = new_buf;
		m_Size = new_buf_size;
		m_Length = new_buf_size - 1;
		//m_ref_counts = new int(1);
	}

	// 空间够
	else {
		m_Length = s_len + m_Length;
	}
	// 连接新字符串
	strcat(m_Buff, s);
	return *this;
}

CMyString & CMyString::SetString_Deep(const CMyString & obj)
{
	return SetString_Deep(obj.m_Buff);
}


int CMyString::IsEmpty()
{
	if (m_Buff == NULL)
	{
		return 0;
	}
	return 1;
}

void CMyString::Init() 
{
	m_Buff = NULL;
	m_Length = 0;
	m_Size = 0;
}

void CMyString::Fnit() 
{

	if (m_Buff != NULL)
	{
		delete[] m_Buff;
		m_Buff = NULL;
	}

	m_Length = 0;
	m_Size = 0;
}

int CMyString::Compare(const char * s) const
{
	return strcmp(m_Buff, s);
}

int CMyString::Compare(const CMyString & obj) const
{
	return strcmp(m_Buff, obj.m_Buff);
}

char * CMyString::AllocBuff(int size)
{
	char *buf = new char[size];
	if (buf != NULL)
	{
		buf[0] = '\0';
	}
	return buf;
}

CMyString operator+(const char * s, const CMyString & obj)
{
	CMyString ret(s);
	ret.SetString_Deep(obj);
	return ret;
}




