// Save.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <STRING.H>
#include <IOSTREAM>
#include <FSTREAM>
#include <AFX.H>
using namespace std;

/*
1.¼Ì³ÐCObject

*/
class CPerson :public CObject
{
public:
  CPerson()
  {
    m_szName[0] = '\0';
  }
  CPerson(const char *pszName)
  {
    strcpy(m_szClassName, "CPerson");
    SetName(pszName);
  }

  static CPerson* CreateObject()
  {
    return new CPerson();
  }

  virtual ~CPerson()
  {
  }
  virtual const char* GetClassName()
  {
    return m_szClassName;
  }
  
  void SetName(const char *pszName)
  {
    strcpy(m_szName, pszName);
  }
  const char* GetName()
  {
    return m_szName;
  }

  friend ofstream& operator<< (ofstream& os, const CPerson& obj)
  {
    os.write(obj.m_szName, sizeof(obj.m_szName));
    return os;
  }

  friend ifstream& operator>> (ifstream& is, CPerson& obj)
  {
    is.read(obj.m_szName, sizeof(obj.m_szName));
    return is;
  }
private:
  char m_szName[4];
protected:
  char m_szClassName[10];
};

class CStudent :public CPerson
{
public:
  CStudent()
  {
    m_nID = 0;
  }
  CStudent(int nID, const char *pszName)
    :CPerson(pszName), m_nID(nID)
  {
    strcpy(m_szClassName, "CStudent");
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

  friend ofstream& operator<< (ofstream& os, const CStudent& obj)
  {
    os.write((char*)&obj.m_nID, sizeof(obj.m_nID));
    os << (CPerson&)obj;
    return os;
  }

  friend ifstream& operator>> (ifstream& is, CStudent& obj)
  {
    is.read((char*)&obj.m_nID, sizeof(obj.m_nID));
    is >> (CPerson&)obj;
    return is;
  }
private:
  int m_nID;
};


int main(int argc, char* argv[])
{
  CPerson  persion("aa");
  CStudent student(1, "bb");


	return 0;
}

