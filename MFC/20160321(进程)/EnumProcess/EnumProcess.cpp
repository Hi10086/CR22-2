// EnumProcess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WINDOWS.H>
#include <Tlhelp32.h>
#include <Psapi.h>

#pragma comment(lib, "Psapi.lib")

int main(int argc, char* argv[])
{
  //创建进程快照
  //EnumProcess
  PROCESSENTRY32 pe;
  pe.dwSize = sizeof(pe);
  int nCount = 0;

  HANDLE hSnapshot = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  if (INVALID_HANDLE_VALUE != hSnapshot)
  {
    if (!Process32First(hSnapshot, &pe))
        return 0;

    printf("%-20s%-10s%-10s%-20s\r\n", "映像名称", "进程ID", "线程数量", "进程路径");
    do 
    {
      //获取进程路径
      char szPath[MAX_PATH] = {0};
      HMODULE hModule = NULL;//::GetModuleHandle("kernel32.dll");
      HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe.th32ProcessID);
      ::GetModuleFileNameEx(hProcess, hModule, szPath, sizeof(szPath));

      //显示
      printf("%-20s%-10d%-10d%-20s\r\n", pe.szExeFile, pe.th32ProcessID, 
             pe.cntThreads, szPath);
      nCount++;
    } 
    while (Process32Next(hSnapshot, &pe));

    printf("count:%d\r\n", nCount);
    ::CloseHandle(hSnapshot);
  }

	return 0;
}

