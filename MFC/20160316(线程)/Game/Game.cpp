// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.H>

//�̻߳ص�����
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
  //���߳�����
  while(true)
  {
    // GetCurrentThreadId()
    OutputDebugString("run2...");
    Sleep(1000); //�ó�ʣ�µ�ʱ��Ƭ �����߳�
  }
}


//�߳�
int main(int argc, char* argv[])
{
  //�����߳�
  DWORD dwThreadID;
  HANDLE  hThread = CreateThread(NULL, 
                                  0, 
                                  ThreadProc, 
                                  NULL, 
                                  0 /*����ִ��*/, 
                                  &dwThreadID);
  if (hThread == NULL)
    return 0;

  //���߳�����
  while(true)
  {
    OutputDebugString("run1...");
    Sleep(1000);
  }

	return 0;
}

