// Use.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../FirstDll/FirstDll.h"
//#pragma comment(lib, "../FirstDll/Debug/FirstDll.lib")
#include <WINDOWS.H>

/*
dll����·��:
��ǰ·��
ϵͳĿ¼
sytem32
SysWOW64
��������
*/


/*
1.��̬ʹ��
2.��̬ʹ��
*/
class CMyTest
{
};

typedef void (CMyTest::*FUNTYPE)();

union Conver
{
  FUNTYPE m_pfn;
  void    *m_p;
};


typedef CTest* (*CRAETE_OBJECT)();


int main(int argc, char* argv[])
{
  //��̬ʹ��
//   CTest test;
//   test.ShowMsg();
// 
//   printf("%d", g_nNumber);
//   ShowMsg();


  //��̬ʹ��
  BOOL b;
  HMODULE hDll = LoadLibrary("FirstDll.dll"); //���ü���++
  hDll = LoadLibrary("FirstDll.dll");
  if (hDll != NULL)
  {
    //������
    CMyTest *pObject = (CMyTest*)new char[0x1000];
    
    //��ȡ��������ַ
    Conver conver;
    conver.m_p = (void*)GetProcAddress(hDll, "??0CTest@@QAE@XZ");
    (pObject->*conver.m_pfn)();

    conver.m_p = (void*)GetProcAddress(hDll, "?ShowMsg@@YGXXZ");
    (pObject->*conver.m_pfn)();


    conver.m_p = (void*)GetProcAddress(hDll, "??1CTest@@UAE@XZ");
    (pObject->*conver.m_pfn)();

    delete[] (void*)pObject;


    //����2��
    CRAETE_OBJECT pfnCreateObj = (CRAETE_OBJECT)GetProcAddress(hDll, "?CreateObject@@YAPAVCTest@@XZ");;
    CTest *pTest = pfnCreateObj();
    pTest->ShowMsg();

    b = FreeLibrary(hDll); //���ü���--
    b = FreeLibrary(hDll);
    b = FreeLibrary(hDll);
  }




  return 0;
}

