// UseDll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <STDLIB.H>
__declspec(dllimport) char g_szBuff[MAXBYTE];
#pragma comment(lib, "../SharedDll/Debug/SharedDll.lib")

int main(int argc, char* argv[])
{
  system("pause");
  printf("%s\n", g_szBuff);
  scanf("%s", g_szBuff);
	printf("%s\n", g_szBuff);
	return 0;
}

