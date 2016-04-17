#include "HackDll.h"
#include <WINDOWS.H>

void ShowMessage()
{
  //调用原来的
  HMODULE hDll = LoadLibrary("kernei32.dll");

  //做事情
  ::MessageBox(NULL, "你被劫持了", NULL, MB_OK);

  //不影响原来功能
  FARPROC pfnShowMessage = GetProcAddress(hDll, "ShowMessage");
  pfnShowMessage();

  FreeLibrary(hDll);
}
