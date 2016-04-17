// Use.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../FirstDll/FirstDll.h"
//#pragma comment(lib, "../FirstDll/Debug/FirstDll.lib")
#include <WINDOWS.H>

/*
dll搜索路径:
当前路径
系统目录
sytem32
SysWOW64
环境变量
*/


/*
1.动态使用
2.静态使用
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
  //静态使用
//   CTest test;
//   test.ShowMsg();
// 
//   printf("%d", g_nNumber);
//   ShowMsg();


  //动态使用
  BOOL b;
  HMODULE hDll = LoadLibrary("FirstDll.dll"); //引用计数++
  hDll = LoadLibrary("FirstDll.dll");
  if (hDll != NULL)
  {
    //调用类
    CMyTest *pObject = (CMyTest*)new char[0x1000];
    
    //获取构函数地址
    Conver conver;
    conver.m_p = (void*)GetProcAddress(hDll, "??0CTest@@QAE@XZ");
    (pObject->*conver.m_pfn)();

    conver.m_p = (void*)GetProcAddress(hDll, "?ShowMsg@@YGXXZ");
    (pObject->*conver.m_pfn)();


    conver.m_p = (void*)GetProcAddress(hDll, "??1CTest@@UAE@XZ");
    (pObject->*conver.m_pfn)();

    delete[] (void*)pObject;


    //方法2：
    CRAETE_OBJECT pfnCreateObj = (CRAETE_OBJECT)GetProcAddress(hDll, "?CreateObject@@YAPAVCTest@@XZ");;
    CTest *pTest = pfnCreateObj();
    pTest->ShowMsg();

    b = FreeLibrary(hDll); //引用计数--
    b = FreeLibrary(hDll);
    b = FreeLibrary(hDll);
  }




  return 0;
}

