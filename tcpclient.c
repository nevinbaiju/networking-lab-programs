#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	struct sockaddr_in address;
	int sock,recvread,con;
	char message[100],buffer[100];

	printf("\nEnter message from client:");
	scanf("%s",message);

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock<0)
	{
		printf("\nSocket Error");
	}

	address.sin_family = AF_INET;
	address.sin_port =7891;
	address.sin_addr.s_addr = INADDR_ANY;


	con=connect(sock,(struct sockaddr *)&address, sizeof(address));
	
	if(con<0)
	{
		printf("\nConnection error\n");
	}

	send(sock,message,sizeof(message),0);

	recvread=recv(sock,buffer,sizeof(buffer),0);
	printf("\n%s\n\n",buffer);

}
