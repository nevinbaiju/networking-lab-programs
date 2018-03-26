//Program:IPC using message queue
// Author Nevin Baiju



#include<stdio.h>
#include<sys/msg.h>

//structure for message

struct msgbuff
{
	long msgtype;
	char msgs[400];
}s1,s1_key;//variables of structure

//main function

void main()
{
	int i,k,mid; //mid to get message id

	mid=msgget(1500,IPC_CREAT|0666);
	k=msgrcv(mid,&s1,400,1,0);
	printf("Message from client is:%s\n",s1.msgs); //message from client
	for(i=0;s1.msgs[i]!='\0';i++)
	{
		if(s1.msgs[i]==' ')
		{
			continue;		
		}
		else if(s1.msgs[i]=='z')     //encoding part of program
		{
			s1.msgs[i]='b';		
		}	
		else if(s1.msgs[i]=='y')
		{
			s1.msgs[i]='a';		
		}	
	
		else
		{
			s1.msgs[i]=s1.msgs[i]+2;		
		}	
	}
	s1.msgtype=2;
	k=msgsnd(mid,&s1,400,0);
	if(k!=-1)                      //checking condition 
	{
		printf("Encoded message successfully send to client\n");		
	}
	else
	{
		printf("Error!!!!!!!!");	
	}

	
}
	