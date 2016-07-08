#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct msg    /*message struct*/
{
	long type;
	char text[BUFSIZ];
};

int main()
{
	int qid;
	key_t key;
	int len1,len2;
	struct  msg pmsg_w,pmsg_r;

	key=IPC_PRIVATE;
	if((qid=msgget(key,IPC_CREAT|0666))<0)   /*create message queue*/
	{
		perror("msgget:create");
		exit(EXIT_FAILURE);
	}
	puts("Enter message to post:");
	if(fgets(pmsg_w.text,BUFSIZ,stdin)==NULL)  /* get message*/
	{
		puts("Wrong,no message to post.\n");
		exit(EXIT_FAILURE);
	}
	pmsg_w.type=10;
	len1=strlen(pmsg_w.text);
	if(msgsnd(qid,&pmsg_w,len1,IPC_NOWAIT)<0)   /*put message into queue*/
	{
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}
	puts("message posted.");
	puts("*************************");

	len2=msgrcv(qid,&pmsg_r,BUFSIZ,10,IPC_NOWAIT|MSG_NOERROR);  /*get message from queue*/
	if(len2>0) 
	{
		printf("reading queue id=%05d\n",qid );
		printf("message type=%ld\n",pmsg_r.type);
		printf("message length=%d\n",len2);
		printf("message text=%s",pmsg_r.text);
	}
	else
	{
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}