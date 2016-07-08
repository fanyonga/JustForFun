#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int main(int argc,char **argv)
{
	pid_t pid,old_ppid,new_ppid;
	pid_t child,parent;
	parent=getpid();
	if((child=fork())<0)
	{
		printf("fork error");
		exit(1);
	}
	else if(child==0)
	{//子进程被调度
		old_ppid=getppid();
		sleep(2);
		new_ppid=getppid();
	}
	else
	{
		sleep(1);
		exit(0);//父进程退出，此时子进程会被指派一个新的父进程，其pid为1
	}

	printf("Original parent:%d\n",parent);
	printf("Child:%d\n",getpid());
	printf("Child's old ppid:%d\n",old_ppid);
	printf("Child's new_ppid:%d\n",new_ppid);
	return 0;
}
