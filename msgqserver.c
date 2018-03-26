
//Program:IPC using message queue


#include<stdio.h>
#include<sys/msg.h>

//structure for message

struct msgbuff
{
	long msgtype;
	char msgs[400];
}s1,s2,s1_key;  //variables of structure

//main function

void main()
{
	int k,mid;  //mid to get message id

	printf("Enter the message:"); //getting input from user
	gets(s1.msgs);
	s1.msgtype=1;
	
	

	mid=msgget(1500,IPC_CREAT|0666);  
	k=msgsnd(mid,&s1,400,0);   //systemcall to swend message
	
	k=msgrcv(mid,&s2,400,2,0); //systemcall to receive message
	printf("Encoded message from string is:%s\n",s2.msgs);
	msgctl(mid, IPC_RMID, NULL);
	

}

