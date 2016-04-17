// TalkClinet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SocketInit.h"
#include <process.h>
#include <STRING.H>

CSocketInit g_init;

#define ECHO_REQUEST 8  //�����Ӧ
#define ECHO_REPLY   0  //��Ӧ

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
  USHORT nSourPort ;   // Դ�˿ں�16bit
  USHORT nDestPort ;   // Ŀ�Ķ˿ں�16bit
  USHORT nLength ;   // ���ݰ�����16bit
  USHORT nCheckSum ;   // У���16bit
}UDP_HEADER, *PUDP_HEADER;

typedef struct _TCP_HEADER 
{
  USHORT nSourPort ;   // Դ�˿ں�16bit
  USHORT nDestPort ;   // Ŀ�Ķ˿ں�16bit
  UINT nSequNum ;   // ���к�32bit
  UINT nAcknowledgeNum ; // ȷ�Ϻ�32bit
  USHORT nHLenAndFlag ;  // ǰ4λ��TCPͷ���ȣ���6λ����������6λ����־λ16bit
  USHORT nWindowSize ;  // ���ڴ�С16bit
  USHORT nCheckSum ;   // �����16bit
  USHORT nrgentPointer ;  // ��������ƫ����16bit
}TCP_HEADER, *PTCP_HEADER ;


struct icmp_hdr 
{
  BYTE icmp_type;     //����
  BYTE icmp_code;     //����
  USHORT icmp_cksum;  //Ч���
  USHORT icmp_id;     //n
  USHORT icmp_seq;    //n
  ULONG  icmp_data;   //GetTickout()
};

//����У����Ǳ�У������16λֵ�ķ����(ones-complement sum)
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
  SOCKET Socket = socket(AF_INET, /*Э����*/
                        SOCK_RAW,  /*ԭʼ�׽���*/
                        IPPROTO_ICMP /*Э��*/);
  if (INVALID_SOCKET == Socket)
  {
    ShowErrorMsg();
    return 0;
  }

  hostent *pHost = gethostbyname(argv[1]);
  if (pHost == NULL)
  {
    printf("Ping �����Ҳ������� %s����������ƣ�Ȼ�����ԡ�\r\n", argv[1]);
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

    //���У���
    if (CalcCheckSum((unsigned short*)pICMP, sizeof(szData)) == 0)
    {
      if (pICMP->icmp_id == i && pICMP->icmp_seq == i)
      {
        printf("���� %s �Ļظ�: �ֽ�=%d ʱ��<%dms TTL=%d\r\n", 
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

