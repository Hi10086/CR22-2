// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.H>

int g_nNumber = 0;
HANDLE g_hEvent;

//�̻߳ص�����
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
  for (int i = 0; i < 1000000; i++)
  {
    //�ȴ��ź�
    WaitForSingleObject(g_hEvent, INFINITE);
    g_nNumber++;
    SetEvent(g_hEvent); //�����ź�
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
  g_hEvent = CreateEvent(NULL, FALSE, TRUE, NULL);
  
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
    //�ȴ��ź�
    WaitForSingleObject(g_hEvent, INFINITE);
    g_nNumber++;
    SetEvent(g_hEvent); //�����ź�
  }

  //�ȴ�ָ���߳̽���, ����ǰ�̣߳��ó���ǰʱ��Ƭ
  WaitForSingleObject(hThread, INFINITE /*һֱ�ȴ�*/);

  printf("g_nNumber=%d\r\n", g_nNumber);
	return 0;
}

