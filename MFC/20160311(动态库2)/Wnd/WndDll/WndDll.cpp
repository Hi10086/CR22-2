// WndDll.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "resource.h"

HINSTANCE g_hIns;

INT_PTR CALLBACK DialogProc(HWND hwndDlg,  
                            UINT uMsg,     
                            WPARAM wParam, 
                            LPARAM lParam  )
{
  switch(uMsg)
  {
  case WM_INITDIALOG:
    break;
  case WM_CLOSE:
    EndDialog(hwndDlg, 0);
    break;
  case WM_COMMAND:
    {
      WORD wNotifyCode = HIWORD(wParam); 
      WORD wID = LOWORD(wParam); 
      HWND hwndCtl = (HWND)lParam;
      if (wID == IDOK || wID == IDCANCEL)
      {
        EndDialog(hwndDlg, 0);
      }
    }
    break;
  }
  return FALSE;
}

void __stdcall ShowDialog()
{
  DialogBox(g_hIns, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
}


BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    g_hIns = (HINSTANCE)hModule;
    return TRUE;
}

