
#include "FirstDll.h"
#include <WINDOWS.H>

int g_nNumber = 1;


void ShowMsg()
{
  ::MessageBox(NULL, "ShowMsg", NULL, MB_OK);
}


CTest::CTest()
{
}

CTest::~CTest()
{
}

void CTest::ShowMsg()
{
  ::ShowMsg();
}

CTest* CreateObject()
{
  return new CTest();
}
