#include <stdio.h>

int g_nData = 1;

extern "C" __declspec(dllexport) void Strcpy()
{
  printf("strcpy2\r\n");
}

extern "C" __declspec(dllexport)  void Strcat()
{
  printf("strcat\r\n");
}