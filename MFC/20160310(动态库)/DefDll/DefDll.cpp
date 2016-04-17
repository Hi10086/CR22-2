
#include "DefDll.h"

int g_nNumber = 1;

void __stdcall ShowMessageEx()
{
  ::MessageBox(NULL, "hello", "", MB_OK);
}