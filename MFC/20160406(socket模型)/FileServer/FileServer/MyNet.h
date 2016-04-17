#pragma once
#include "Strtok.h"

#pragma pack(push)
#pragma pack(1)
struct tagPacket
{
    unsigned short m_length;
    char m_data[1];
};

#pragma pack(pop)

struct tagFpSock
{
    HANDLE hFile;
    SOCKET socket;
    FILE *fp;
    int nCopys;
};

int ClientStart(int sockType);
int ServerStart(sockaddr *addr, int sockType, bool isAsyn);
unsigned int __stdcall FileThread(void *lpParam);
int MyRecv(tagPacket **buf _Out_, SOCKET socket _In_);
int MySend(SOCKET Socket, const char *pszCmd);