#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include <string.h>
#include<arpa/inet.h>

void main()
{
	struct sockaddr_in serv_addr,client_addr;
	char to[100],from[100],sub[100],msg[100],buf[100];
	int sock,i,r,flag=0,s,t,f,m,slen=sizeof(client_addr);

	strcpy(buf,"Received at server");	

	sock=socket(AF_INET, SOCK_DGRAM, 0);
	if(sock<0)
		printf("\nSocket Creation Error\n");

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = 7889;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	
	bind(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	while(1)
	{
		printf("\nWaiting for data..\n");

		t=recvfrom(sock, to, sizeof(to), 0, (struct sockaddr *) &client_addr,&slen);
		f=recvfrom(sock, from, sizeof(from), 0, (struct sockaddr *) &client_addr,&slen);
		s=recvfrom(sock, sub, sizeof(sub), 0, (struct sockaddr *) &client_addr,&slen);
		m=recvfrom(sock, msg, sizeof(msg), 0, (struct sockaddr *) &client_addr,&slen);
		
		for(i=0;to[i]!='\0';i++)
		 	if(to[i]=='@')
				flag=1;
		
		if(flag==1)
		{

			printf("\nFrom:%s",from);
			printf("\nSub:%s",sub);
			printf("\nMessage:%s",msg);
		
			r=sendto(sock , buf , sizeof(buf) , 0 , (struct sockaddr*) &client_addr, sizeof(client_addr));
			if(r<0)
				printf("\nSending Error");
			else
				printf("\nSent");	
		}	
		else
		{
			printf("validation error");
			r=sendto(sock , "Check To: address" , 20 , 0 , (struct sockaddr*) &client_addr, sizeof(client_addr));
			if(r<0)
				printf("\nSending Error");
			else
				printf("\nSent");	

		}
	}
}

