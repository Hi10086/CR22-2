// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "String.h"
#include "../String/String.h" //Ïà¶ÔÂ·¾¶ d:/string.h
#include <stdlib.h>

#pragma comment(lib, "../string/debug/string.lib")


int main(int argc, char* argv[])
{
  printf("g_nData=%d\r\n", g_nData);
	Strcpy();
  system("pause");
	return 0;
}

