//Program created by Nevin Baiju
//Roll num:241
//R6
#include<stdio.h>
#include<sys/types.h>

void main()
{
pid_t pid;
pid=fork();

if (pid==-1)
 {
   printf("ERROR!");
  }
   else if (pid==0)
    {
      printf("\nchild process");
      printf("\nProcess id of child process: %d \n",getpid());
      printf("\nProcess id of parent process: %d \n",getppid());
     }
    else if(pid>0)
     {
       printf("\nparent process");
       printf("\nProcess id of parent process: %d \n",getpid());
      }
}
