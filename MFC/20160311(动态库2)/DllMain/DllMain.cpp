// DllMain.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

//DllMain不是必须的
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch(ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
      ::MessageBox(NULL, "进程加载", NULL, MB_OK); //进程首次加载此模块
      break;
    case DLL_PROCESS_DETACH:
      ::MessageBox(NULL, "进程卸载", NULL, MB_OK); //进程能卸载此模块
      break;
    case DLL_THREAD_ATTACH:
      ::MessageBox(NULL, "线程加载", NULL, MB_OK);
      break;
    case DLL_THREAD_DETACH:
      ::MessageBox(NULL, "线程卸载", NULL, MB_OK);
      break;
    }
    return TRUE;
}

