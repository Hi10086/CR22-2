// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.H>
#include <process.h>

int g_nNumber = 0;
BOOL g_isEnd;

//�̻߳ص�����
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
���߳�ͬ��:
  ʲôʱ�����������̷߳���ͬһ����Դ��
1.�¼�����
2.�ź���
3.������
4.�ٽ���
5.��������
*/

int main(int argc, char* argv[])
{
  //�����߳�
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

