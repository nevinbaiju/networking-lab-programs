#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include <string.h>
#include<arpa/inet.h>

void main()
{
	struct sockaddr_in client_addr;
	char buffer[1024],to[100],from[100],sub[100],msg[100];
	int sock,r,t,f,s,m,slen=sizeof(client_addr);

	sock=socket(AF_INET, SOCK_DGRAM, 0);
	if(sock<0)
		printf("\nSocket Creation Error\n");

	client_addr.sin_family = AF_INET;
	client_addr.sin_port = 7889;
	client_addr.sin_addr.s_addr = INADDR_ANY;
	
	while(1)
	{
		printf("\nTo: ");
		scanf("%s",to);
		printf("\nFrom: ");
		scanf("%s",from);
		printf("Sub: ");
		scanf("%s",sub);
		printf("Message: ");
		scanf("%s",msg);

		t=sendto(sock, to, sizeof(to) , 0 , (struct sockaddr *) &client_addr, slen);
		f=sendto(sock, from, sizeof(from) , 0 , (struct sockaddr *) &client_addr, slen);
		s=sendto(sock, sub, sizeof(sub) , 0 , (struct sockaddr *) &client_addr, slen);
		m=sendto(sock, msg, sizeof(msg) , 0 , (struct sockaddr *) &client_addr, slen);
		

		r=recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &client_addr , &slen);
		if(r<0)
			printf("\nReceiving Error");
		else
			printf("\n%s\n",buffer);

	}
}
