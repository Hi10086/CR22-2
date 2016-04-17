// InjectDll.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
      ::MessageBox(NULL, "Œ“¿¥¡À", "Inject", MB_OK);
    }
    else if (ul_reason_for_call == DLL_PROCESS_DETACH)
    {
      ::MessageBox(NULL, "886", "Inject", MB_OK);
    }

    return TRUE;
}

