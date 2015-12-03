#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<sys/shm.h>
/*
 *<linux/sem.h><linux/shm.h>库太旧了，更新为以上库
 *不知为何semun没有定义，重新定义一下总算运行正常
 */
union semun {
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
	struct seminfo *__buf;
};
int emptyid;
int fullid;
main()
{
	int chld;
	struct sembuf P,V;
	union semun arg;
	
	int shmid;
	char* viraddr;
	char buffer[BUFSIZ];
	
	emptyid=semget(IPC_PRIVATE,1,IPC_CREAT|0666);
	fullid=semget(IPC_PRIVATE,1,IPC_PRIVATE|0666);
	arg.val=1;
	if(semctl(emptyid,0,SETVAL,arg)==-1)
	  perror("semctl setval error");
	arg.val=0;
	if(semctl(fullid,0,SETVAL,arg)==-1)
	  perror("semctl setval error");

	P.sem_num=0;
	P.sem_op=-1;
	P.sem_flg=SEM_UNDO;
	V.sem_num=0;
	V.sem_op=1;
	V.sem_flg=SEM_UNDO;

	shmid=shmget(IPC_PRIVATE,BUFSIZ,0666|IPC_CREAT);
	viraddr=(char*)shmat(shmid,NULL,0);
	//sprintf(viraddr,"%d",shmat(shmid,0,0));
	while((chld=fork())==-1);

	if(chld>0)
	{
		while(1)
		{
			semop(fullid,&P,1);
			printf("Your Message is :%s\n",viraddr);
			semop(emptyid,&V,1);
			if(strncmp(viraddr,"end",3) == 0) break;
		}
		wait(0);
		shmdt(viraddr);
		shmctl(shmid,IPC_RMID,0);
		semctl(emptyid,IPC_RMID,0);
		semctl(fullid,IPC_RMID,0);
		printf("Parent exit!\n");
		exit(0);
	}
	else
	{
		while(1)
		{
			semop(emptyid,&P,1);
			puts("Enter your text:\n");
			fgets(buffer,BUFSIZ,stdin);
			strcpy(viraddr,buffer);
			semop(fullid,&V,1);
			if(strncmp(viraddr,"end",3)==0)
			{
				sleep(1);
				break;
			}
		}
		printf("Child exit!\n");
		exit(0);
	}
}
