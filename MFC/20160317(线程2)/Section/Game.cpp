// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.H>

int g_nNumber = 0;
CRITICAL_SECTION g_cs; //�ٽ�������(���ɿ����ͬ��)

//�̻߳ص�����
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
  DWORD dwThreadID = GetCurrentThreadId();
  for (int i = 0; i < 1000000; i++)
  {
    EnterCriticalSection(&g_cs); //�����ٽ���
    g_nNumber++;
    LeaveCriticalSection(&g_cs); //�˳��ٽ���
  }

  return 0;
}


/*
���߳�ͬ��:
  ʲôʱ�����������̷߳���ͬһ����Դ��
1.�¼�����
2.������
3.�ź���
4.�ٽ���
5.��������
*/

int main(int argc, char* argv[])
{
  //�����ź���
  DWORD dwThreadID = GetCurrentThreadId();
  InitializeCriticalSection(&g_cs);

  
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
    EnterCriticalSection(&g_cs); //�����ٽ���
    g_nNumber++;
    LeaveCriticalSection(&g_cs); //�˳��ٽ���
  }

  //�ȴ�ָ���߳̽���, ����ǰ�̣߳��ó���ǰʱ��Ƭ
  WaitForSingleObject(hThread, INFINITE /*һֱ�ȴ�*/);

  printf("g_nNumber=%d\r\n", g_nNumber);
	return 0;
}

