#pragma  once
/*define some protocal*/
#define XNS_IDP 0x0600
#define DLOG 0x0661
#define IP 0x0800
#define X75 0x0801
#define NBS 0x0802
#define ECMA 0x0803
#define Chaosnet 0x0804
#define X25L3 0x0805
#define ARP 0x0806
#define FARP 0x0808
#define RFR 0x6559
#define RARP 0x8035
#define NNIPX 0x8037
#define EtherTalk 0x809B
#define ISSE 0x80D5
#define AARP 0x80F3
#define EAPS 0x8100
#define IPX 0x8137
#define SNMP 0x814C
#define IPv6 0x86DD
#define OAM 0x8809
#define PPP 0x880B
#define GSMP 0x880C
#define MPLSu 0x8847
#define MPLSm 0x8848
#define PPPoEds 0x8863
#define PPPoEss 0x8864
#define LWAPP 0x88BB
#define LLDP 0x88CC
#define EAP 0x8E88
#define LOOPBACK 0x9000
#define VLAN 0x9100

/*define some ip type*/
#define ICMP 1
#define IGMP 2
#define TCP 6
#define UDP 17
#define OSPF 89

/*gotten packet*/
typedef struct packet
{
	struct pcap_pkthdr *header;
	const u_char *pkt_data;
}packet;

/* 4 bytes IP address */ 
typedef struct ip_address 
{ 
	u_char byte1; 
	u_char byte2; 
	u_char byte3; 
	u_char byte4; 
}ip_address; 

/*ethernet header*/
typedef struct ethernet_header
{
	u_char dstmac[6]; //Ŀ��mac��ַ
	u_char srcmac[6]; //Դmac��ַ
	u_short eth_type; //��̫������
}ethernet_header;

/* IPv4 header */ 
typedef struct ip_header 
{ 
	u_char ihl:4; /* Internet header length (4 bits)*/ 
	u_char ver:4;/*Version (4 bits)*/
	u_char tos; /* Type of service */ 
	u_short tlen; /* Total length */ 
	u_short identification; /* Identification */  
	u_short fo:13; /* Fragment offset (13 bits)*/ 
	u_short flags:3;/*Flags (3 bits) */
	u_char ttl; /* Time to live */ 
	u_char proto; /* Protocol */ 
	u_short crc; /* Header checksum */ 
	ip_address saddr;/* Source address */ 
	ip_address daddr;/* Destination address */ 
	u_int op_pad; /* Option + Padding */ 
}ip_header; 

/* UDP header */ 
typedef struct udp_header 
{ 
	u_short sport; /* Source port */ 
	u_short dport; /* Destination port */ 
	u_short len; /* Datagram length */ 
	u_short crc; /* Checksum */ 
}udp_header; 

typedef struct tcp_header  //20 bytes : default
{
	u_short sport;      //Source port
	u_short dport;      //Destination port
	u_long seqno;       //Sequence no
	u_long ackno;       //Ack no
	u_char reserved_1:4; //����6λ�е�4λ�ײ�����
	u_char offset:4;     //tcpͷ������
	u_char flag:6;       //6λ��־
	u_char reserved_2:2; //����6λ�е�2λ
	//FIN - 0x01
	//SYN - 0x02
	//RST - 0x04 
	//PUSH- 0x08
	//ACK- 0x10
	//URG- 0x20
	//ACE- 0x40
	//CWR- 0x80

	u_short win;
	u_short checksum;
	u_short uptr;
}tcp_header;

/*ARP/RARP header*/
typedef struct arp_header   //28 bytes
{
	u_short hrd;       //hardware address space=0x0001
	u_short eth_type;  //Ethernet type ....=0x0800
	u_char maclen;     //Length of mac address=6
	u_char iplen;      //Length of ip addres=4
	u_short opcode;    //Request =1 Reply=2 (highbyte)
	u_char smac[6];    //source mac address
	ip_address saddr;  //Source ip address
	u_char dmac[6];    //Destination mac address
	ip_address daddr;  //Destination ip address
}arp_header,rarp_header;

//ICMP Header
typedef struct icmp_header
{
	u_char type;	  //type
	u_char code;      //code
	u_short chk_sum;  //checksum 16bit
	u_short id; 
	u_short seq; 
	u_long timestamp; 
}icmp_header;

typedef struct igmp_header
{
	u_char type;	  //type
	u_char mrtime;		//Max Response time
	u_short chk_sum;
	u_long mcadd;	//Multicast address
}igmp_header;

typedef struct http_packet
{
	CString request_method;  // ��������ķ�������GET��POST��HEAD��OPTIONS��PUT��DELETE��TARCE
	CString request_uri;     // ���������URI����/sample.jsp
	CString request_Protocol_version;// ���������Э���Э��İ汾,��HTTP/1.1

	CString request_accept;  // ���������Accept���� */*
	CString request_referer; // ���������Referer���� http://www.gucas.ac.cn/gucascn/index.aspx
	CString request_accept_language;  // ��������� Accept-language���� zh-cn
	CString request_accept_encoding;  // ��������� Accept_encoding���� gzip��deflate
	CString request_modified_date;  // ���������If-Modified-Since���� Sun,27 Sep 2009 02:33:14 GMT
	CString request_match;         // ���������If-None-Match���� "011d3dc1a3fcal:319"
	CString request_user_agent;  // ���������User-Agent���� Mozilla/4.0(compatible:MSIE 6.0;Windows NT 5.1;SV1;.NET CLR 1.1.4322;.NEt...
	CString request_host;      // ���������Host���� www.gucas.ac.cn
	CString request_connection;// ���������Connection���� Keep-Alive
	CString request_cookie;    // ���������Cookie���� ASP.NET_SessionId=hw15u245x23tqr45ef4jaiqc

	CString request_entity_boy;// ���������ʵ������
	//===================================================================================
	CString respond_Protocol_version; // ������ӦЭ���Э��İ汾,��HTTP/1.1
	CString respond_status;         // ������Ӧ״̬���룬��200
	CString respond_description;  // ������Ӧ״̬������ı���������OK

	CString respond_content_type; // ������Ӧ���ݵ����ͣ���text/html
	CString respond_charset;      // ������Ӧ�ַ�����UTF-8
	CString respond_content_length; // ������Ӧ���ݵĳ��ȣ���9
	CString respond_connection; // ������Ӧ����״̬����close
	CString respond_Cache_Control; // ������Ӧ����״̬����private
	CString respond_X_Powered_By; // ������Ӧ����״̬����ASP.NET
	CString respond_X_AspNet_Version; // ������Ӧ����״̬����1.1.4322
	CString respond_Set_Cookie; // ������Ӧ����״̬����ASP.NET_SessionId=w0qojdwi0welb4550lafq55;path=/

	CString respond_date;       // ������Ӧ���ڣ���fri,23 Oct 2009 11:15:31 GMT
	CString respond_Etag;       // �������޸ģ���"Ocld8a8cc91:319"
	CString respond_server;     // ������Ӧ������lighttpd

	CString respond_entity_boy; // ������Ӧʵ�����壬��IMOld(8);
}http_packet;
