// SharedDll.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

//∂®“Âdllπ≤œÌ∂Œ
#pragma data_seg("MY_DATA")
char g_szBuff[MAXBYTE] = "hello";
#pragma data_seg()
#pragma comment(linker, "/SECTION:MY_DATA,RWS");

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved)
{
    return TRUE;
}

