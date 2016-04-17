// CallWnd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void __stdcall ShowDialog();

#pragma comment(lib, "../WndDll/Debug/WndDll.lib")

int main(int argc, char* argv[])
{
	ShowDialog();
	return 0;
}

