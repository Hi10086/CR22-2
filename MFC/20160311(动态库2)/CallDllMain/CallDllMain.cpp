// CallDllMain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WINDOWS.H>

int main(int argc, char* argv[])
{
  HMODULE hDll = LoadLibrary("../dllmain/debug/dllmain.dll");
  hDll = LoadLibrary("../dllmain/debug/dllmain.dll");

  FreeLibrary(hDll);
  FreeLibrary(hDll);
	return 0;
}

