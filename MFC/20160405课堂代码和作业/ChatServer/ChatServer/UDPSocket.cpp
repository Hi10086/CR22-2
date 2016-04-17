#include "stdafx.h"
#include "UDPSocket.h"

bool CUDPSocket::SendUdpData(const char *msg, int to_socket, sockaddr *to_addr)
{
    int len = ::strlen(msg) + sizeof(char) + (int)(((tagPacket*)NULL)->m_data);
    tagPacket *packet = (tagPacket *)new char[len];
    packet->m_length = len;
    ::strcpy(packet->m_data, msg);

    // 发送数据
    int result = ::sendto(to_socket, (const char *)packet, len, 0, to_addr, sizeof(*to_addr));
    if (result == -1)
        return false;

    return true;
}

int CUDPSocket::RecvUdpData(char *buf, int flags, sockaddr* from, int *from_len)
{
    int result = 0;
    unsigned short length;
    int total = sizeof(length);
    int recvbytes = 0;
    sockaddr addr;
    int addr_size = sizeof(addr);

    // 接收长度
    //while(recvbytes < total)
    //{
        result = recvfrom(m_socket, (char*)&length + recvbytes, total - recvbytes, 0, &addr, &addr_size);
    //    if (/*result == -1 || */result == 0)
    //    {
    //        return result;
    //    }
    //    recvbytes += result;
    //}

    // 接收数据
    tagPacket *packet = (tagPacket*)new char[length];
    packet->m_length = length;

    total = length - sizeof(packet->m_length);
    recvbytes = 0;
    while(recvbytes < total)
    {
        result = recvfrom(m_socket, packet->m_data + recvbytes, total - recvbytes, 0, from, from_len);
        if (-1 == result || result == 0)
        {
            delete[] packet;
            return result;
        }
        recvbytes += result;
    }

    buf = (char*)packet;
    return result;
}

CUDPSocket::CUDPSocket(void)
{
}


CUDPSocket::~CUDPSocket(void)
{
}
