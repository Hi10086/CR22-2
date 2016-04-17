// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.H>

int g_nNumber = 0;
HANDLE g_hMutex;

//�̻߳ص�����
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
  DWORD dwThreadID = GetCurrentThreadId();
  for (int i = 0; i < 1000000; i++)
  {
    //�ȴ�����Ȩ
    WaitForSingleObject(g_hMutex, INFINITE);
    g_nNumber++;
    ReleaseMutex(g_hMutex); //�ͷ�����Ȩ
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
  DWORD dwThreadID = GetCurrentThreadId();
  g_hMutex = CreateMutex(NULL, FALSE, NULL); 

  //�ͷ�����Ȩ
  //ReleaseMutex(g_hMutex);
  
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
    //�ȴ�����Ȩ
    WaitForSingleObject(g_hMutex, INFINITE);
    g_nNumber++;
    ReleaseMutex(g_hMutex); //�ͷ�����Ȩ
  }

  //�ȴ�ָ���߳̽���, ����ǰ�̣߳��ó���ǰʱ��Ƭ
  WaitForSingleObject(hThread, INFINITE /*һֱ�ȴ�*/);

  printf("g_nNumber=%d\r\n", g_nNumber);
	return 0;
}

