#include "HackDll.h"
#include <WINDOWS.H>

void ShowMessage()
{
  //����ԭ����
  HMODULE hDll = LoadLibrary("kernei32.dll");

  //������
  ::MessageBox(NULL, "�㱻�ٳ���", NULL, MB_OK);

  //��Ӱ��ԭ������
  FARPROC pfnShowMessage = GetProcAddress(hDll, "ShowMessage");
  pfnShowMessage();

  FreeLibrary(hDll);
}
