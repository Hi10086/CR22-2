// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.H>

//线程回调函数
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
  //新线程运行
  while(true)
  {
    // GetCurrentThreadId()
    OutputDebugString("run2...");
    Sleep(1000); //让出剩下的时间片 挂起线程
  }
}


//线程
int main(int argc, char* argv[])
{
  //创建线程
  DWORD dwThreadID;
  HANDLE  hThread = CreateThread(NULL, 
                                  0, 
                                  ThreadProc, 
                                  NULL, 
                                  0 /*立即执行*/, 
                                  &dwThreadID);
  if (hThread == NULL)
    return 0;

  //主线程运行
  while(true)
  {
    OutputDebugString("run1...");
    Sleep(1000);
  }

	return 0;
}

