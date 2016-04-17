// MFCSerialize.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <STRING.H>
#include <AFX.H>

/*
1.�̳�CObject
2.��дSerialize�麯��
3.DECLARE_SERIAL( CPerson )
4.ʵ��һ��Ĭ�Ϲ��캯��
5.DECLARE_SERIAL
*/

class CPerson :public CObject
{
  DECLARE_SERIAL(CPerson)
public:
  virtual void Serialize(CArchive& ar)
  {
    //�жϱ��滹�Ƕ�ȡ
    if (ar.IsStoring())
    {
      //����
      ar.Write(m_szName, sizeof(m_szName));
    }
    else
    {
      //��ȡ
      ar.Read(m_szName, sizeof(m_szName));
    }
  }
public:
  CPerson()
  {
    m_szName[0] = '\0';
  }
  CPerson(const char *pszName)
  {
    SetName(pszName);
  }

  virtual ~CPerson()
  {
  }
  
  void SetName(const char *pszName)
  {
    strcpy(m_szName, pszName);
  }
  const char* GetName()
  {
    return m_szName;
  }
private:
  char m_szName[4];
};

IMPLEMENT_SERIAL(CPerson, CObject, 1)


class CStudent :public CPerson
{
  DECLARE_SERIAL(CStudent)
public:
  virtual void Serialize(CArchive& ar)
  {
    CPerson::Serialize(ar);

    //�жϱ��滹�Ƕ�ȡ
    if (ar.IsStoring())
    {
      //����
      ar.Write((char*)&m_nID, sizeof(m_nID));
    }
    else
    {
      //��ȡ
      ar.Read((char*)&m_nID, sizeof(m_nID));
    }
  }
public:
  CStudent()
  {
    m_nID = 0;
  }
  CStudent(int nID, const char *pszName)
    :CPerson(pszName), m_nID(nID)
  {
  }
  
  virtual ~CStudent()
  {
  }
  
  void SetID(int nID)
  {
    m_nID = nID;
  }
  int GetID()
  {
    return m_nID;
  }
private:
  int m_nID;
};
IMPLEMENT_SERIAL(CStudent, CObject, 1)

int main(int argc, char* argv[])
{
  
  
  try
  {
    CPerson per1("aa1");
    CPerson per2("aa2");
    CStudent stu(1, "bb");
    CFile file("stu.dat", CFile::modeReadWrite |  CFile::modeCreate);
    CArchive ar(&file, CArchive::store);
    ar << (CObject*)&per1;
    ar << (CObject*)&per2;
  }
  catch(CMemoryException* e)
  {
    int n = 0;
  }
  catch(CArchiveException* e)
  {
    int n = 0;
  }
  catch(CFileException* e)
  {
    int n = 0;
  }


  //��ȡ
  CFile file2("stu.dat", CFile::modeReadWrite);
  CArchive ar2(&file2, CArchive::load);
  CPerson *pObject1;
  CPerson *pObject2;
  

  ar2 >> pObject1 >> pObject2;

  delete pObject1;
  delete pObject2;
	return 0;
}

