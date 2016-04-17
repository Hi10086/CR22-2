#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "ssocket.h"


#pragma pack(1)
struct tagPacket
{
    unsigned short m_length;
    char m_data[1];
};

#pragma pack(8)

class CUDPSocket :
    public CSSocket
{
public:
    virtual bool SendUdpData(const char *msg, int to_socket, sockaddr *to_addr);
    virtual int RecvUdpData(char *buf, int flags, sockaddr* from, int *from_len);
public:
    CUDPSocket(void);
    virtual ~CUDPSocket(void);
//private:
//    virtual int TcpSocket(sockaddr){ return 0; };
//    virtual bool SendTcpData(const char *, int){ return true; };
//    virtual int RecvTcpData(int, char *, int){ return 0; };
};

