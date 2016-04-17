// CallDef.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WINDOWS.H>

int main(int argc, char* argv[])
{
  HMODULE hDll = LoadLibrary("defdll.dll");

  //ÐòºÅµ÷ÓÃ
  void *pfn = GetProcAddress(hDll, (char*)1);

  FreeLibrary(hDll);
	return 0;
}

