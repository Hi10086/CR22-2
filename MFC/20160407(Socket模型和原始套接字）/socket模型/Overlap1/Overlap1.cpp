// Overlap1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <winsock2.h>
#include <stdio.h>

 

#define PORT    12345
#define MSGSIZE 1024

 

#pragma comment(lib, "ws2_32.lib")

typedef struct
{
 WSAOVERLAPPED overlap;
 WSABUF        Buffer;
 char          szMessage[MSGSIZE];
 DWORD         NumberOfBytesRecvd;
 DWORD         Flags;
}PER_IO_OPERATION_DATA, *LPPER_IO_OPERATION_DATA;

 
int                     g_nTotalConn = 0;
SOCKET                  g_CliSocketAry[MAXIMUM_WAIT_OBJECTS];
WSAEVENT                g_CliEventAry[MAXIMUM_WAIT_OBJECTS];
LPPER_IO_OPERATION_DATA g_pPerIODataAry[MAXIMUM_WAIT_OBJECTS];

 
DWORD WINAPI WorkerThread(LPVOID);

void Cleanup(int);

int main()

{

 WSADATA     wsaData;
 SOCKET      sListen, sClient;
 SOCKADDR_IN local, client;
 DWORD       dwThreadId;
 int         iaddrSize = sizeof(SOCKADDR_IN);

 // Initialize Windows Socket library
 WSAStartup(0x0202, &wsaData);


 // Create listening socket
 sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

 

 // Bind
 local.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
 local.sin_family = AF_INET;
 local.sin_port = htons(PORT);
 bind(sListen, (struct sockaddr *)&local, sizeof(SOCKADDR_IN));

 // Listen
 listen(sListen, 3);

 // Create worker thread
 CreateThread(NULL, 0, WorkerThread, NULL, 0, &dwThreadId); 

 while (TRUE)
 {
    // Accept a connection
    sClient = accept(sListen, (struct sockaddr *)&client, &iaddrSize);
    printf("Accepted client:%s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
    g_CliSocketAry[g_nTotalConn] = sClient;

    // Allocate a PER_IO_OPERATION_DATA structure
    g_pPerIODataAry[g_nTotalConn] = (LPPER_IO_OPERATION_DATA)HeapAlloc(
                  GetProcessHeap(),
                  HEAP_ZERO_MEMORY,
                  sizeof(PER_IO_OPERATION_DATA));
    g_pPerIODataAry[g_nTotalConn]->Buffer.len = MSGSIZE;
    g_pPerIODataAry[g_nTotalConn]->Buffer.buf = g_pPerIODataAry[g_nTotalConn]->szMessage;
    g_CliEventAry[g_nTotalConn] = g_pPerIODataAry[g_nTotalConn]->overlap.hEvent = WSACreateEvent();

 

    // Launch an asynchronous operation
    WSARecv(
      g_CliSocketAry[g_nTotalConn],
      &g_pPerIODataAry[g_nTotalConn]->Buffer,
      1,
      &g_pPerIODataAry[g_nTotalConn]->NumberOfBytesRecvd,
      &g_pPerIODataAry[g_nTotalConn]->Flags,
      &g_pPerIODataAry[g_nTotalConn]->overlap,
      NULL);

    g_nTotalConn++;

 }

 closesocket(sListen);
 WSACleanup();
 return 0;
}

 

DWORD WINAPI WorkerThread(LPVOID lpParam)

{
 int   ret, index;
 DWORD cbTransferred;

 while (TRUE)
 {
    ret = WSAWaitForMultipleEvents(g_nTotalConn, g_CliEventAry, FALSE, 1000, FALSE);
    if (ret == WSA_WAIT_FAILED || ret == WSA_WAIT_TIMEOUT)
    {
      continue;
    }


    index = ret - WSA_WAIT_EVENT_0;
    WSAResetEvent(g_CliEventAry[index]);

    WSAGetOverlappedResult(
                          g_CliSocketAry[index],
                          &g_pPerIODataAry[index]->overlap,
                          &cbTransferred,
                          TRUE,
                          &g_pPerIODataAry[g_nTotalConn]->Flags);

 

    if (cbTransferred == 0)
    {
      // The connection was closed by client
      Cleanup(index);
    }
    else
    {
      // g_pPerIODataAry[index]->szMessage contains the received data
      g_pPerIODataAry[index]->szMessage[cbTransferred] = '\0';
      send(g_CliSocketAry[index], g_pPerIODataAry[index]->szMessage,\
          cbTransferred, 0);

 
      
      // Launch another asynchronous operation
      WSARecv(
        g_CliSocketAry[index],
        &g_pPerIODataAry[index]->Buffer,
        1,
        &g_pPerIODataAry[index]->NumberOfBytesRecvd,
        &g_pPerIODataAry[index]->Flags,
        &g_pPerIODataAry[index]->overlap,
        NULL);

      puts(g_pPerIODataAry[index]->Buffer.buf);
    }
 }

 return 0;
}

 

void Cleanup(int index)

{
 closesocket(g_CliSocketAry[index]);
 WSACloseEvent(g_CliEventAry[index]);
 HeapFree(GetProcessHeap(), 0, g_pPerIODataAry[index]);

 if (index < g_nTotalConn - 1)
 {
    g_CliSocketAry[index] = g_CliSocketAry[g_nTotalConn - 1];
    g_CliEventAry[index] = g_CliEventAry[g_nTotalConn - 1];
    g_pPerIODataAry[index] = g_pPerIODataAry[g_nTotalConn - 1];
 }

 g_pPerIODataAry[--g_nTotalConn] = NULL;
}