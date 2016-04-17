#include "stdafx.h"
#include "SSocket.h"

int TEMPSIZE = 255;

CSSocket::CSSocket(void)
{
    m_socket = -1;
    m_sock_type = 0;
}


CSSocket::~CSSocket(void)
{
    if (m_socket != -1)
    {
        closesocket(m_socket);
    }  
}

int CSSocket::TcpSocket(sockaddr addr)
{
    // 创建
    m_socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m_socket != -1)
    {
        // 绑定
        if (::bind(m_socket, &addr, sizeof(addr)) == -1)
        {
            ::closesocket(m_socket);
            m_socket = -1;
            return -1;
        }

        m_sock_type = SOCK_STREAM;
        m_addr = addr;
    }

    return m_socket;
}

int CSSocket::UdpSocket(sockaddr addr)
{
    // 创建
    m_socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (m_socket != -1)
    {
        // 绑定
        if (::bind(m_socket, &addr, sizeof(addr)) == -1)
        {
            ::closesocket(m_socket);
            m_socket = -1;
            return -1;
        }

        m_sock_type = SOCK_DGRAM;
        m_addr = addr;
    }

    return m_socket;
}

bool CSSocket::SendData(const char *msg, int to_socket, sockaddr *to_addr /*= NULL*/)
{
    // 无发送数据 或未初始化
    if (msg == NULL || m_sock_type == 0 || to_socket == -1)
    {
        return false;
    }
    else if (m_sock_type == SOCK_STREAM)
    {
        return SendTcpData(msg, to_socket);
    }
    else if (m_sock_type == SOCK_DGRAM && to_addr != NULL)
    {
        return SendUdpData(msg, to_socket, to_addr);
    }

    return false;
}

int CSSocket::RecvData(int from_socket, char *buf, int flags, sockaddr* from /*= NULL*/, int *from_len /*= NULL*/)
{
    if (m_sock_type == 0)
    {
        return NULL;
    }
    else if (m_sock_type == SOCK_STREAM && from_socket != -1)
    {
        return RecvTcpData(from_socket, buf, flags);
    }
    else if (m_sock_type == SOCK_DGRAM && from != NULL && from_len > 0)
    {
        return RecvUdpData(buf, flags, from, from_len);
    }

    return NULL;
}

bool CSSocket::SendTcpData(const char *msg, int to_socket)
{
    size_t len = ::strlen(msg);
    if (::send(to_socket, msg, len, 0) != len)
        return false;
    return true;
}

bool CSSocket::SendUdpData(const char *msg, int to_socket, sockaddr *to_addr)
{
    size_t len = ::strlen(msg);
    if (::sendto(to_socket, msg, len, 0, to_addr, sizeof(to_addr)) != len)
        return false;
    return true;
}

int CSSocket::RecvTcpData(int to_socket, char *buf, int flags)
{
    buf = new char[TEMPSIZE];
    if (buf == NULL)
        return 0;
    return ::recv(to_socket, buf, TEMPSIZE, flags);
}

int CSSocket::RecvUdpData(char *buf, int flags, sockaddr* from, int *from_len)
{
    buf = new char[TEMPSIZE];
    if (buf == NULL)
        return 0;
    return ::recvfrom(m_socket, buf, TEMPSIZE, flags, from, from_len);
}
