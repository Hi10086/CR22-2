// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.H>

int g_nNumber = 0;
HANDLE g_hMutex;

//线程回调函数
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
  DWORD dwThreadID = GetCurrentThreadId();
  for (int i = 0; i < 1000000; i++)
  {
    //等待所有权
    WaitForSingleObject(g_hMutex, INFINITE);
    g_nNumber++;
    ReleaseMutex(g_hMutex); //释放所有权
  }

  return 0;
}


/*
多线程同步:
  什么时候产生，多个线程访问同一个资源。
1.事件对象
2.互斥体
3.信号量
4.临界区
5.。。。。
*/

int main(int argc, char* argv[])
{
  DWORD dwThreadID = GetCurrentThreadId();
  g_hMutex = CreateMutex(NULL, FALSE, NULL); 

  //释放所有权
  //ReleaseMutex(g_hMutex);
  
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
    //等待所有权
    WaitForSingleObject(g_hMutex, INFINITE);
    g_nNumber++;
    ReleaseMutex(g_hMutex); //释放所有权
  }

  //等待指定线程结束, 挂起当前线程，让出当前时间片
  WaitForSingleObject(hThread, INFINITE /*一直等待*/);

  printf("g_nNumber=%d\r\n", g_nNumber);
	return 0;
}

