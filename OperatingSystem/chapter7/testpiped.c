#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc,char **argv)
{
	static const char mesg[]="happy new year to you!";
	char buf[BUFSIZ];
	size_t rcount,wcount;
	int p_fd[2];
	size_t n;

	if(pipe(p_fd)<0)	/*create pipe*/
	{
		perror("pipe failed");
		exit(1);
	}

	printf("Read end=fd %d,write end=fd %d\n",p_fd[0],p_fd[1] );
	n=strlen(mesg);
	if((wcount=write(p_fd[1],mesg,n))!=n){   /*write data*/
		perror("write failed");
		exit(1);
	}
	if((rcount=read(p_fd[0],buf,BUFSIZ))!=wcount){ /*read data*/
		perror("read failed");
		exit(1);
	}

	buf[rcount]='\0';
	printf("Read<%s> from pipe\n",buf );
	close(p_fd[0]);
	close(p_fd[1]);
	return 0;
}