// DllMain.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

//DllMain���Ǳ����
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch(ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
      ::MessageBox(NULL, "���̼���", NULL, MB_OK); //�����״μ��ش�ģ��
      break;
    case DLL_PROCESS_DETACH:
      ::MessageBox(NULL, "����ж��", NULL, MB_OK); //������ж�ش�ģ��
      break;
    case DLL_THREAD_ATTACH:
      ::MessageBox(NULL, "�̼߳���", NULL, MB_OK);
      break;
    case DLL_THREAD_DETACH:
      ::MessageBox(NULL, "�߳�ж��", NULL, MB_OK);
      break;
    }
    return TRUE;
}

