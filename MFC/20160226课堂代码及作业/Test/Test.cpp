// Test.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

INT_PTR CALLBACK DialogProc(HWND hwndDlg,  // handle to dialog box
                            UINT uMsg,     // message  
                            WPARAM wParam, // first message parameter
                            LPARAM lParam  )
{
  switch(uMsg)
  {
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  case WM_CLOSE:
    DestroyWindow(hwndDlg);
    break;
  case WM_INITDIALOG:
    {
      SetFocus(hwndDlg);
    }
    break;
  case WM_KEYDOWN:
    {
      ::MessageBox(NULL, "WM_KEYDOWN", NULL, MB_OK);
    }
    break;
  }
  return FALSE;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
  HWND hDlg = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
  ShowWindow(hDlg, SW_NORMAL);

  BOOL bRet;
  MSG msg;
  while( (bRet = GetMessage( &msg, NULL, 0, 0 )) != 0)
  { 
    if (msg.message == WM_KEYDOWN)
    {
      SendMessage(hDlg, msg.message, msg.wParam, msg.lParam);
    }

    if (bRet == -1)
    {
      // handle the error and possibly exit
    }
    else
    {
      TranslateMessage(&msg); 
      DispatchMessage(&msg); 
    }
  }
	return 0;
}



