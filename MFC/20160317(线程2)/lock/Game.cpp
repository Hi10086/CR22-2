// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.H>

int g_nNumber = 0;

//线程回调函数
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
  DWORD dwThreadID = GetCurrentThreadId();
  for (int i = 0; i < 1000000; i++)
  {
    InterlockedIncrement((LPLONG)&g_nNumber);
  }

  return 0;
}

int main(int argc, char* argv[])
{
  DWORD dwThreadID = GetCurrentThreadId();

  //创建线程
  HANDLE  hThread = CreateThread(NULL, 
                                  0, 
                                  ThreadProc, 
                                  NULL, 
                                  0, 
                                  NULL);
  if (hThread == NULL)
    return 0;

  for (int i = 0; i < 1000000; i++)
  {
    //lock xadd
    InterlockedIncrement((LPLONG)&g_nNumber);
  }

  //等待指定线程结束, 挂起当前线程，让出当前时间片
  WaitForSingleObject(hThread, INFINITE /*一直等待*/);

  printf("g_nNumber=%d\r\n", g_nNumber);
	return 0;
}

