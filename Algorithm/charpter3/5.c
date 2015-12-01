#include<stdio.h>
/*
 * 经典的汉诺塔问题
 * A B C A为起点塔 B为中继塔 C为重点塔
 * n 盘c子的个数
 * count 移动盘子的次数
 * main() 输出盘子的移动路径并输出其总次数
 */

int count=0;

void hanoi(int n,char a ,char b,char c)
{
	if(n>0)
	{
		hanoi(n-1,a,c,b);
		printf("No. %d disk movepath : %c  ------>  %c  \n",n,a,c);
		count++;
		hanoi(n-1,b,a,c);
	}
}

main()
{
	int n;
	printf("Plese input the number of disk :");
	scanf("%d",&n);
	printf("------------Move start------------\n");
	hanoi(n,'A','B','C');
	printf("------------Move complete---------\n");
	printf("the total number of movepath : %d\n",count);
}


