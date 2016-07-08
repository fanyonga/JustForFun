#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	int fd1,fd2,fd3,nbytes;
	int flag=O_CREAT|O_TRUNC|O_WRONLY;
	char buf[10];

	if((fd1=open("readAndwriteFile.c",O_RDONLY,0644))<0)
	{
		perror("open readAndwriteFile.c");
		exit(EXIT_FAILURE);
	}
	if((fd2=open("/dev/null",O_WRONLY,0644))<0)
	{
		perror("/dev/null");
		exit(EXIT_FAILURE);
	}
	if((fd1=open("/tmp/foo.bar",flag,0644))<0)
	{
		perror("open /tmp/foo.bar");
		exit(EXIT_FAILURE);
	}
	while((nbytes=read(fd1,buf,10))>0)
	{
		if(write(fd2,buf,10)<0)
			perror("write /dev/null");
		if(write(fd3,buf,nbytes)<0)
			perror("/tmp/foo.bar");
		write(STDOUT_FILENO,buf,10);
	}
	close(fd1);
	close(fd2);
	close(fd3);

	exit(EXIT_SUCCESS);
}