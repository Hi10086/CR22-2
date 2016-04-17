// TalkClinet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SocketInit.h"
#include <process.h>
#include <STRING.H>

CSocketInit g_init;

#define ECHO_REQUEST 8  //请求回应
#define ECHO_REPLY   0  //回应

struct ip_hdr
{
  unsigned char h_len:4;         //length of header
  unsigned char version:4;      //Version of IP
  unsigned char tos;               //Type of service
  unsigned short total_len;     //total length of the packet
  unsigned short ident;          //unique identifier
  unsigned short frag_and_flags; //flags
  unsigned char ttl;          //ttl
  unsigned char proto;        //protocol(TCP ,UDP etc)
  unsigned short checksum;    //IP checksum
  unsigned int sourceIP;
  unsigned int destIP;
};

typedef struct _UDP_HEADER 
{
  USHORT nSourPort ;   // 源端口号16bit
  USHORT nDestPort ;   // 目的端口号16bit
  USHORT nLength ;   // 数据包长度16bit
  USHORT nCheckSum ;   // 校验和16bit
}UDP_HEADER, *PUDP_HEADER;

typedef struct _TCP_HEADER 
{
  USHORT nSourPort ;   // 源端口号16bit
  USHORT nDestPort ;   // 目的端口号16bit
  UINT nSequNum ;   // 序列号32bit
  UINT nAcknowledgeNum ; // 确认号32bit
  USHORT nHLenAndFlag ;  // 前4位：TCP头长度；中6位：保留；后6位：标志位16bit
  USHORT nWindowSize ;  // 窗口大小16bit
  USHORT nCheckSum ;   // 检验和16bit
  USHORT nrgentPointer ;  // 紧急数据偏移量16bit
}TCP_HEADER, *PTCP_HEADER ;


struct icmp_hdr 
{
  BYTE icmp_type;     //类型
  BYTE icmp_code;     //代码
  USHORT icmp_cksum;  //效验和
  USHORT icmp_id;     //n
  USHORT icmp_seq;    //n
  ULONG  icmp_data;   //GetTickout()
};

//网际校验和是被校验数据16位值的反码和(ones-complement sum)
WORD CalcCheckSum(IN unsigned short* addr,IN int len)
{
  int		nleft = len;
  int		sum = 0;
  unsigned short* w = addr;
  unsigned short answer = 0;
  
  while(nleft > 1) {
    sum += *w++;
    nleft -= 2;
  }
  
  if(nleft == 1) {
    *(unsigned char*)(&answer) = *(unsigned char*)w;
    sum += answer;
  }
  
  sum = (sum >> 16) + (sum & 0xffff);
  sum += (sum >> 16);
  answer = ~sum;
  
  return (answer);
}



int main(int argc, char* argv[])
{
  int n = sizeof(ip_hdr);
  SOCKET Socket = socket(AF_INET, /*协议族*/
                        SOCK_RAW,  /*原始套接字*/
                        IPPROTO_ICMP /*协议*/);
  if (INVALID_SOCKET == Socket)
  {
    ShowErrorMsg();
    return 0;
  }

  hostent *pHost = gethostbyname(argv[1]);
  if (pHost == NULL)
  {
    printf("Ping 请求找不到主机 %s。请检查该名称，然后重试。\r\n", argv[1]);
    return 0;
  }
  
  sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = 0;
  addr.sin_addr.S_un.S_addr = ((long**)pHost->h_addr_list)[0][0];

  char szData[32];

  for (int i = 0; i < 10; i++)
  {
    icmp_hdr *pIcmp = (icmp_hdr*)szData;
    pIcmp->icmp_type = ECHO_REQUEST;
    pIcmp->icmp_code = 0;
    pIcmp->icmp_data = ::GetTickCount();
    pIcmp->icmp_id = i;
    pIcmp->icmp_seq = i;
    pIcmp->icmp_cksum = 0;
    pIcmp->icmp_cksum = CalcCheckSum((unsigned short*)szData, sizeof(szData));

    int nResult = sendto(Socket, szData, sizeof(szData), 0, 
                         (sockaddr*)&addr, sizeof(addr));

    char szRecv[MAXBYTE];
    sockaddr_in ServerAddr;
    int nLen = sizeof(ServerAddr);
    nResult = recvfrom(Socket, szRecv, sizeof(szRecv), 0, 
                      (sockaddr*)&ServerAddr, &nLen);

    ip_hdr *pIP = (ip_hdr*)szRecv;
    icmp_hdr *pICMP = (icmp_hdr*)(pIP + 1);

    //检查校验和
    if (CalcCheckSum((unsigned short*)pICMP, sizeof(szData)) == 0)
    {
      if (pICMP->icmp_id == i && pICMP->icmp_seq == i)
      {
        printf("来自 %s 的回复: 字节=%d 时间<%dms TTL=%d\r\n", 
          inet_ntoa(ServerAddr.sin_addr), 
          sizeof(szData), 
          ::GetTickCount() - pICMP->icmp_data,
          pIP->ttl);
      }
    }

    Sleep(1000);
  }

  closesocket(Socket);
	return 0;
}

