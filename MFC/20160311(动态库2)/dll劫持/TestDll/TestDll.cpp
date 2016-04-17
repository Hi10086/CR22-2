#include "TestDll.h"
#include <WINDOWS.H>

void __stdcall ShowMessage()
{
  ::MessageBox(NULL, "ShowMsg", NULL, MB_OK);
}