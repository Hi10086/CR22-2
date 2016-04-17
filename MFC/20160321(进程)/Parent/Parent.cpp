// Parent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WINDOWS.H>

#define PATH "F:\\CR22\\MFC\\进程\\SubProcess\\Debug\\SubProcess.exe 1.txt"

int main(int argc, char* argv[])
{
  STARTUPINFO si = {0};
  si.cb = sizeof(si);
  PROCESS_INFORMATION pi;
  SECURITY_ATTRIBUTES sa = {0};
  sa.nLength = sizeof(sa);
  sa.bInheritHandle = TRUE; //句柄可以被继承
  HANDLE hEvent = ::CreateEvent(&sa, TRUE, FALSE, NULL);

  if (!::CreateProcess(NULL, PATH, NULL, NULL, 
      TRUE,  //继承句柄
      NULL,
      NULL, 
      NULL, 
      &si, 
      &pi))
  {
    return 0;
  }

  WaitForSingleObject(hEvent, -1);
  printf("Hello World!\n");
	return 0;
}

