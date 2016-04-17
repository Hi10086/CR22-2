// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.H>
#include <process.h>

int g_nNumber = 0;
BOOL g_isEnd;

//线程回调函数
unsigned int WINAPI ThreadProc(LPVOID lpParameter)
{
  while(true)
  {
    printf("run2...\r\n");
    Sleep(100);
  }

  return 0;
}


/*
多线程同步:
  什么时候产生，多个线程访问同一个资源。
1.事件对象
2.信号量
3.互斥体
4.临界区
5.。。。。
*/

int main(int argc, char* argv[])
{
  //创建线程
  HANDLE  hThread = (HANDLE)_beginthreadex(NULL, 
                                  0, 
                                  ThreadProc, 
                                  NULL, 
                                  0, 
                                  NULL);
  if (hThread == NULL)
    return 0;

  while(true)
  {
    printf("run1...\r\n");
    Sleep(100);
  }

	return 0;
}

