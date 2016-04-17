#pragma once
#include <Winsock2.h>
#pragma comment(lib, "Ws2_32.lib")


class CSSocket
{
protected:
    int m_socket;
    sockaddr m_addr;
    int m_sock_type;
public:
    CSSocket(void);
    virtual ~CSSocket(void);
public:
    virtual int TcpSocket(sockaddr addr);
    virtual int UdpSocket(sockaddr addr);


    bool SendData(const char *msg, int to_socket, sockaddr *to_addr = NULL);
    int RecvData(int to_socket, _Out_ char *buf, int flags = 0, _Inout_ sockaddr* from = NULL, _Inout_ int *from_len = NULL);

protected:
    // 请重写下面的处理函数, 默认直接发送
    virtual bool SendTcpData(const char *msg, int to_socket);
    virtual bool SendUdpData(const char *msg, int to_socket, sockaddr *to_addr);
    virtual int RecvTcpData(int to_socket, char *buf, int flags);
    virtual int RecvUdpData(char *buf, int flags, sockaddr* from, int *from_len);
private:
    bool bind();
};

