// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.H>

int g_nNumber = 0;

//�̻߳ص�����
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

  //�����߳�
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

  //�ȴ�ָ���߳̽���, ����ǰ�̣߳��ó���ǰʱ��Ƭ
  WaitForSingleObject(hThread, INFINITE /*һֱ�ȴ�*/);

  printf("g_nNumber=%d\r\n", g_nNumber);
	return 0;
}

