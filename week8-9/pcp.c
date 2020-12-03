#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#define buffer_size 2
int main()
{
	int count=0;
	int pip[2]; //storing ends of pipe
	int nbytes;
	pid_t pid;
	int res;
	res=pipe(pip);
	char item[buffer_size];
	char buffer[buffer_size];
		if(res==-1)
	{
		printf("ERROR: Failed pipe\n");
		return 1;
	}
	pid=fork();

	if(pid<0)
	{
		printf("ERROR: failed to fork a child\n");
		return 1;
	}
	else if(pid>0)// parent : consumer
	{
		wait(NULL);
		close(pip[1]);
		
		while ((nbytes = read(pip[0], buffer, 2)) > 0) 
         	{
           		 printf("Consumer : recieved %s\n",buffer);
			
		}
		close(pip[0]);
	}
	else // child : producer
	{
		while(count++<10)
		{
			//printf("inside parent\n");
			close(pip[0]);
			sprintf(item,"%d",count);
			write(pip[1],item,2);
			printf("Producer : sent %s\n",item);
		}
			exit(0);
		
	}
	
}

