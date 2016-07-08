#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include <stdlib.h>
#include<sys/wait.h>

int main()
{
	pid_t child;
	int status,retval;

	if((child=fork())<0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	printf("Child's PID:%d\n",child );
	if(child==0)
	{
		sleep(2);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if((waitpid(child,&status,WNOHANG))==0)
		{
			retval=kill(child,SIGKILL);
			if(retval)
			{
				puts("kill failed\n");
				perror("kill");
				waitpid(child,&status,0);
			}
			else printf("%d killed\n",child );
		}
	}
	exit(EXIT_SUCCESS);
}