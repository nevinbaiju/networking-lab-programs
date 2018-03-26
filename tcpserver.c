#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	struct sockaddr_in address;
	int server_fd,new_socket,recvread,addrlen,opt=1;
	char message[100],buffer[100];

	addrlen = sizeof(address);	

	strcpy(message,"The message was recived from the Server");
	
	server_fd=socket(AF_INET,SOCK_STREAM,0);
	if(server_fd<0)
	{
		printf("Socket Error");
	}
	
	//setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt));
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port =7891;

	bind(server_fd,(struct sockaddr *)&address,sizeof(address));

	if(listen(server_fd, 3) < 0)
		printf("\nError...\n");
	else
		printf("\nListening...\n");

	new_socket = accept(server_fd, (struct sockaddr *)&address,(socklen_t*)&addrlen);

	if(new_socket<0)
	{
		printf("Accept Error");
	}

	recv(new_socket,buffer,sizeof(buffer),0);
	printf("\nMessage from Client:%s\n\n",buffer);

	send(new_socket,message,sizeof(message),0);
}
