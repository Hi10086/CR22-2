// Call.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WINDOWS.H>

/*
动态库的使用方式:
  1.动态使用
*/
typedef void (*FUN)();

int main(int argc, char* argv[])
{
  HMODULE hMoudle = LoadLibrary("F:\\CR22\\MFC\\UI2\\库\\动态库\\String\\Debug\\String.dll");

  //调用函数
//   FUN pfn = (FUN)((int)hMoudle + 0x100A);
//   pfn();
  FUN pfn = (FUN)GetProcAddress(hMoudle, "Strcpy");
  pfn();

  FreeLibrary(hMoudle);
	return 0;
}

