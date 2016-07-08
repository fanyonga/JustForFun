#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	int field[2];
	pid_t pid;
	int fd1,status,nbytes;
	char buf_r[20],buf_w[20];

	if((fd1=open("testKill.c",O_RDONLY))<0)
	{
		perror("open testKill.c failed");
		exit(EXIT_FAILURE);
	}

	if(pipe(field)<0)
	{
		perror("pipe failed");
		exit(EXIT_FAILURE);
	}

	if((pid=fork())<0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0)
	{
		nbytes=read(fd1,buf_w,20);
		if(nbytes>0)
		{
			printf("read file success.\n");
			if(write(field[1],buf_w,nbytes)>0)
				printf("write message into piped success.\n");
			close(field[1]);
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		waitpid(pid,&status,0);
		if((nbytes=read(field[0],buf_r,20))>0)
		{
			printf("read from piped success.\n");
			write(STDOUT_FILENO,buf_r,nbytes);
			printf("The length of testKill.c is %d bytes.\n",nbytes);
			close(field[0]);
		}
	}
	exit(EXIT_SUCCESS);
}
