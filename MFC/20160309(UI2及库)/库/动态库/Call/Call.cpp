// Call.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WINDOWS.H>

/*
��̬���ʹ�÷�ʽ:
  1.��̬ʹ��
*/
typedef void (*FUN)();

int main(int argc, char* argv[])
{
  HMODULE hMoudle = LoadLibrary("F:\\CR22\\MFC\\UI2\\��\\��̬��\\String\\Debug\\String.dll");

  //���ú���
//   FUN pfn = (FUN)((int)hMoudle + 0x100A);
//   pfn();
  FUN pfn = (FUN)GetProcAddress(hMoudle, "Strcpy");
  pfn();

  FreeLibrary(hMoudle);
	return 0;
}

