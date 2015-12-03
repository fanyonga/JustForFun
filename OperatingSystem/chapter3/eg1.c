#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<linux/sem.h>

int mutexid;

main()
{
	int chld,i,j;
	struct sembuf P,V;
	union semun arg;

	mutexid=semget(IPC_PRIVATE,1,0666|IPC_CREAT);
	arg.val=1;
	if(semctl(mutexid,0,SETVAL,arg)==-1)
	  perror("semctl setval error");

	P.sem_num=0;
	P.sem_op=-1;
	P.sem_flg=SEM_UNDO;
	V.sem_num=0;
	V.sem_op=1;
	V.sem_flg=SEM_UNDO;

	while((chld=fork())==-1);
	if(chld>0)
	{
		i=1;
		while(i<=3)
		{
			sleep(1);
			semop(mutexid,&P,1);
			printf("prnt in \n");
			sleep(1);
			printf("prnt out \n");
			semop(mutexid,&V,1);
			i++;
		}
		wait(0);
		semctl(mutexid,IPC_RMID,0);
		exit(0);
	}
	else
	{
		j=1;
		while(j<=3)
		{
			sleep(1);
			semop(mutexid,&P,1);
			printf("chld in \n");
			sleep(1);
			printf("chld out \n");
			semop(mutexid,&V,1);
			j++;
		}
		exit(0);
	}
}
