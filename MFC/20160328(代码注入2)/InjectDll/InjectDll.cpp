// InjectDll.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#define IDM_GAME_BASE  0x1000
#define IDM_GAME_START (IDM_GAME_BASE + 0)
#define IDM_GAME_END   (IDM_GAME_BASE + 1)

WNDPROC g_OldProc = NULL;

LRESULT CALLBACK WindowProc(HWND hwnd,      // handle to window
                            UINT uMsg,      // message identifier
                            WPARAM wParam,  // first message parameter
                            LPARAM lParam)
{
    if (uMsg == WM_COMMAND)
    {
      WORD wNotifyCode = HIWORD(wParam); 
      WORD wID = LOWORD(wParam); 
      
      switch (wID)
      {
      case 0x89:
        ::MessageBox(NULL, "7", "Inject", MB_OK);
        break;
      case IDM_GAME_START:
        ::MessageBox(NULL, "��ʼ��Ϸ", "Inject", MB_OK);
        break;
      case IDM_GAME_END:
        ::MessageBox(NULL, "������Ϸ", "Inject", MB_OK);
        break;
      }
    }
    return g_OldProc(hwnd, uMsg, wParam, lParam);
}

DWORD WINAPI ThreadProc(  LPVOID lpParameter)
{
  BOOL bRet;
  MSG msg;
  while( (bRet = GetMessage( &msg, NULL, 0, 0 )) != 0)
  { 
    if (bRet == -1)
    {
      // handle the error and possibly exit
    }
    else
    {
      if (msg.message == 0x123)
      {
        ::MessageBox(NULL, "ThreadProc", NULL, MB_OK);
      }
    }
  }

  return 0;
}


BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
      ::MessageBox(NULL, "������", "Inject", MB_OK);
      
      //�����߳�
      DWORD dwTID;
      ::CreateThread(NULL, 0, ThreadProc, NULL, 0, &dwTID);


      //�����ڴ�ӳ��
      HANDLE hMap = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, "Inject");
      LPVOID lpMap = ::MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);


      //����˵�
      HWND hCalc = ::FindWindowA(NULL, (char*)lpMap);
      *(DWORD*)lpMap = dwTID;
      ::UnmapViewOfFile(lpMap);
      ::CloseHandle(hMap);

      HMENU hMenu = ::GetMenu(hCalc);
      ::AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT_PTR)hMenu, "��Ϸ(&G)");
      
      int nCount = ::GetMenuItemCount(hMenu);
      HMENU hSubMenu = ::GetSubMenu(hMenu, nCount - 1);
      ::AppendMenu(hSubMenu, MF_STRING, IDM_GAME_START, "��ʼ��Ϸ(&S)");
      ::AppendMenu(hSubMenu, MF_STRING, IDM_GAME_END, "������Ϸ(&E)");

      //���໯
      //�жϴ��ڰ汾
      if (IsWindowUnicode(hCalc))
        g_OldProc = (WNDPROC)::SetWindowLongW(hCalc, GWL_WNDPROC, (LONG)WindowProc);
      else
        g_OldProc = (WNDPROC)::SetWindowLongA(hCalc, GWL_WNDPROC, (LONG)WindowProc);
    }
    else if (ul_reason_for_call == DLL_PROCESS_DETACH)
    {
      ::MessageBox(NULL, "886", "Inject", MB_OK);
    }

    return TRUE;
}

