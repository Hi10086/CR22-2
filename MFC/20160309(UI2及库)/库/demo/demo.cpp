// demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../CMyStringLib/MyString.h"
#pragma comment(lib, "../CMyStringLib/Debug/CMyStringLib.lib")

int main(int argc, char* argv[])
{
	CMyString str("Hello World!");
	printf("%s\n", str.GetString());
	return 0;
}

