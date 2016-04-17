#include "stdafx.h"
#include "MyNet.h"

int MySend(SOCKET Socket, const char *pszCmd)
{
    int nResult;
    int nLength = ::strlen(pszCmd) + sizeof(char) + (int)(((tagPacket*)NULL)->m_data);
    tagPacket *pPakcet = (tagPacket*)new char[nLength];

    pPakcet->m_length = nLength;
    strcpy(pPakcet->m_data, pszCmd);

    //��������
    nResult = ::send(Socket, (char*)pPakcet, pPakcet->m_length, 0);
    if (nResult ==  SOCKET_ERROR)
    {
        int a = 0;
    }
    delete[] pPakcet;
    return nResult;
}

int MyRecv(tagPacket **buf _Out_, SOCKET socket _In_)
{
    int result = 0;
    unsigned short length;
    int total = sizeof(length);
    int recvbytes = 0;

    // ���ճ���
    while(recvbytes < total)
    {
        result = ::recv(socket, (char*)&length + recvbytes, total - recvbytes, 0);
        if (result == -1 || result == 0)
        {
            return result;
        }
        recvbytes += result;
    }

    // ��������
    tagPacket *packet = (tagPacket*)new char[length];
    packet->m_length = length;

    total = length - sizeof(packet->m_length);
    recvbytes = 0;
    while(recvbytes < total)
    {
        result = ::recv(socket, packet->m_data + recvbytes, total - recvbytes, 0);
        if (-1 == result || result == 0)
        {
            delete[] packet;
            return result;
        }
        recvbytes += result;
    }

    *buf = packet;
    return result;
}

unsigned int __stdcall FileThread(void *lpParam)
{
    tagFpSock *pFp = (tagFpSock*)lpParam;
    int nResult;
    int recSize;
    int nLen = sizeof(recSize);
    ::getsockopt(pFp->socket, SO_RCVBUF, NULL, (char*)&recSize, &nLen);
    char *pBuf = new char[recSize];

    for (int i = 0; i < pFp->nCopys; i++)
    {    
        nResult = ::recv(pFp->socket, pBuf, recSize, 0); 
        if (nResult > 0)
            ::WriteFile(pFp->hFile, pBuf, nResult, NULL, NULL);
    }

    ::closesocket(pFp->socket);
    ::fclose(pFp->fp);
    delete[] pBuf;
    delete pFp;
    return 0;
}

int ServerStart(sockaddr *addr, int sockType, bool isAsyn)
{
    int m_Socket;
    if (sockType == SOCK_STREAM)
        m_Socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    else
        m_Socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if (m_Socket == INVALID_SOCKET)
        return INVALID_SOCKET;

    if (isAsyn)
    {
        u_long Flag = 1;  
        // ѡ���첽
        if (::ioctlsocket(m_Socket, FIONBIO, &Flag) == SOCKET_ERROR )
            return SOCKET_ERROR;
    }

    if (sockType == SOCK_STREAM)
    {   
        // �󶨶˿�
        if (::bind(m_Socket, addr, sizeof(addr)) == SOCKET_ERROR)
            return SOCKET_ERROR;

        if (::listen(m_Socket, SOMAXCONN) == SOCKET_ERROR)
            return SOCKET_ERROR;
    }

    return m_Socket;
}

int ClientStart(int sockType)
{
    int m_Socket;
    if (sockType == SOCK_STREAM)
        m_Socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    else
        m_Socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (m_Socket == INVALID_SOCKET)
        return INVALID_SOCKET;

    return m_Socket;
}