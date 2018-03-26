//Author :Nevin Baiju
#include<stdio.h>
#include<sys/types.h>
#include<string.h>

pid_t pid;
void main()
{
    int fd1[2],fd2[2],i,p1,p2;
    char string1[20],string2[20],temp[10];

    p1=pipe(fd1);                //Creating Pipe 1
    p2=pipe(fd2);                //Creating Pipe 2

    if(p1==-1||p2==-1)            //Checking pipe Errors
        printf("Error occured while creating pipes");
    else
    {
        printf("\nEnter a string for Parent:");
        scanf("%s",string1);
        printf("Enter a string for Child:");
        scanf("%s",string2);

        pid=fork();            //Creating Child process

        if(pid==-1)            //Child Error condition
            printf("Error while creating process");
        else if(pid==0)            //Inside Child process
        {
            write(fd2[1],string2,sizeof(string2));    //Writing into pipe 2
            read(fd1[0],temp,sizeof(temp));        //Reading from pipe 1
            strcat(string2,temp);
            printf("\nInside Child and the string is %s\n",string2);
        }
        else                 //Inside Parent process
        {
            write(fd1[1],string1,sizeof(string1));    //Writing into pipe 1
            read(fd2[0],temp,sizeof(temp));        //Reading from pipe 2
            strcat(string1,temp);
            printf("\n\nInside Parent and the string is %s\n",string1);
        }
    }
}

