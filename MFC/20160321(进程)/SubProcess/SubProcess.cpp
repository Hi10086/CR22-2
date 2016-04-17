// SubProcess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WINDOWS.H>

int main(int argc, char* argv[])
{
  HANDLE hEvetn = NULL;
  scanf("%d", &hEvetn);
  if (SetEvent(hEvetn))
	  printf("OK!\n");
  else
    printf("Error!\n");
	return 0;
}

