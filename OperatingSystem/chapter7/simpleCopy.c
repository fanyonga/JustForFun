#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char **argv)
{
	int fd1,fd2,nbytes;
	char buf[20];
	printf("%s %s\n",argv[1],argv[2]);
	if((fd1=open(argv[1],O_RDONLY))<0)
	{
		perror("open fd1");
		exit(EXIT_FAILURE);
	}
	if((fd2=open(argv[2],O_WRONLY|O_CREAT))<0)
	{
		perror("open fd2");
		exit(EXIT_FAILURE);
	}
	printf("%d %d\n",fd1,fd2);
	while((nbytes=read(fd1,buf,20))>0)
	{
		if(write(fd2,buf,nbytes)<0) perror("write fd1");
	}
	close(fd1);
	close(fd2);
	return 0;
}