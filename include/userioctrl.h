#ifndef _USER_IOCTL_H_
#define _USER_IOCTL_H_

#define IOCTL_SET_EVENT CTL_CODE(FILE_DEVICE_UNKNOWN,0x800,METHOD_BUFFERED,FILE_READ_DATA|FILE_WRITE_DATA)
#define IOCTL_GET_SHARE_ADDR CTL_CODE(FILE_DEVICE_UNKNOWN,0x801,METHOD_BUFFERED,FILE_READ_DATA|FILE_WRITE_DATA)
#define IOCTL_ADD_RULE CTL_CODE(FILE_DEVICE_UNKNOWN,0x802,METHOD_BUFFERED,FILE_READ_DATA|FILE_WRITE_DATA)
#define IOCTL_REMOVE_RULE CTL_CODE(FILE_DEVICE_UNKNOWN,0x803,METHOD_BUFFERED,FILE_READ_DATA|FILE_WRITE_DATA)

#define TCP_PROTOCOL 0x06
#define UDP_PROTOCOL 0x11
#define ICMP_PROTOCOL 0x01

#define IP_TYPE 0x0008
#define ARP_TYPE 0x0608
#define RARP_TYPE 0x3580

#define LOG_BUFSIZE 64*1024 // 64k

typedef enum _PacketStatus
{
	PacketDrop,
	PacketPass
}PacketStatus;

typedef enum _PackDirection
{
	PACKET_IN,
	PACKET_OUT,
	PACKET_BOTH
} PacketDirection;

typedef struct _PktFltRule
{
	UCHAR srcIpAddr[4];
	UCHAR dstIpAddr[4];
	USHORT srcPort;
	USHORT dstPort;
	UCHAR protocol;
	PacketDirection direction;
	PacketStatus status;
} PktFltRule;

typedef struct _PacketRecord 
{
	USHORT etherType;
	UCHAR srcMac[6];
	UCHAR dstMac[6];
	UCHAR protocol;
	UCHAR srcIP[4];
	USHORT srcPort;
	UCHAR dstIP[4];
	USHORT dstPort;
	UCHAR status;
	ULONG dataLen;
} PacketRecord;

#endif