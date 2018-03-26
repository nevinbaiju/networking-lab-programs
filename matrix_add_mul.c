
#include<stdio.h>
#include<sys/types.h>

void main()
{
	int a[10][10],b[10][10],c[10][10],d[10][10],m,n,i,j;
	printf("\nenter the number of rows and coloumns");
	scanf("%d %d",&m,&n);
	printf("\n enter the first matrix\n");
	for(i=0;i<m;i++)
	{
   		for(j=0;j<n;j++)
    		{
			printf("enter the element in position %d %d \n",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nenter the second matrix\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("enter the element in position %d %d \n",i,j);
			scanf("%d",&b[i][j]);
		}
	}
	pid_t pid;
	pid=fork();

	if (pid==-1)
	{
		printf("ERROR!");
	}
	else if (pid==0)
	{
		printf("\nChild process 1\n");
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				c[i][j]=a[i][j]+b[i][j];
			} 
		}

		printf("\nsum of the two matrices are:\n");
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("/t%d/t" ,c[i][j]);
			}    
			printf("\n");     
		}
	}
	else if(pid>0)
	{
		printf("\nParent process \n");
		pid=fork();
		printf("\nChild process 2\n");
	}
}

