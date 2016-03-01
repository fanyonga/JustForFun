#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<errno.h>
union semun {
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
	struct seminfo *__buf;
};

int mutexid;
int SAid;
int SOid;

main()
{
	struct sembuf P,V;
	union semun arg;

	mutexid=semget(IPC_PRIVATE,1,IPC_CREAT|0666);
	SAid=semget(IPC_PRIVATE,1,IPC_CREAT|0666);
	SOid=semget(IPC_PRIVATE,1,IPC_CREAT|0666);

	arg.val=1;
	if(semctl(mutexid,0,SETVAL,arg)==1)
	  perror("semctl setval error");
	arg.val=0;
	if(semctl(SAid,0,SETVAL,arg)==1)
	  perror("semctl setval error");
	arg.val=0;
	if(semctl(SOid,0,SETVAL,arg)==1)
	  perror("semctl setval error");

	P.sem_num=0;
	P.sem_op=-1;
	P.sem_flg=SEM_UNDO;
	V.sem_num=0;
	V.sem_op=1;
	V.sem_flg=SEM_UNDO;

	printf("Father has three apples.\n");
	printf("Monther has three oranges.\n");
	printf("Son is hungry for orange.\n");
	printf("Daugther is hungry for apple.\n");
	printf("Then Parents start to work.\n\n\n");
	if(fork() == 0)
	{
		int i=0;
		while(i<3)
		{
			semop(mutexid,&P,1);
			printf("Father put an apple\n");
			semop(SAid,&V,1);
			i++;
		}
		sleep(3);
		printf("Father has no apple!\n");
		exit(0);
	}
	else
	{
		if(fork() == 0)
		{
			int i=0;
			while(i<3)
			{
				semop(mutexid,&P,1);
				printf("Mother put an orange\n");
				semop(SOid,&V,1);
				i++;
			}
			sleep(2);
			printf("Mother has no orange\n");
			exit(0);
		}
		else
		{

			if(fork() == 0)
			{
				int i=0;
				while(i<3)
				{
					semop(SOid,&P,1);
					printf("Son get an orange\n");
					semop(mutexid,&V,1);
					printf("Son eat an orange\n");
					sleep(1);
					i++;
				}
				printf("Son is fullness\n");
				exit(0);
	    	}
			else
			{
				
				if(fork() == 0)
				{
					int i=0;
					while(i<3)
					{
						semop(SAid,&P,1);
						printf("Daugther get an apple\n");
						semop(mutexid,&V,1);
						printf("Daugther eat an apple\n");
						sleep(1);
						i++;
					}
					printf("Daugther is Fullness\n");
					exit(0);
				}
			}
		}
	}
	wait(0);
	wait(0);
	wait(0);
	wait(0);
	semctl(mutexid,IPC_RMID,0);
	semctl(SAid,IPC_RMID,0);
	semctl(SOid,IPC_RMID,0);
}
