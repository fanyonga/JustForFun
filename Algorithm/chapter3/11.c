#include<stdio.h>
/*
 *total 竞选学生会主席的总人数
 *n   学生投票选举人的编号
 *main() 统计并输出全校学生投票的结果
 */

main()
{
	int total,n;
	printf("Please input the number of votemen : ");
	scanf("%d",&total);
	int a[total+1];
	for(n=0;n<total+1;n++)//initial 0 in linux
	  a[n]=0;
	printf("Please input the vote in turn(completed tag: -1) :\n");
	while(1)
	{
		scanf("%d",&n);
		if(n == -1)
		{
			break;
		}
		else if(n<=0 || n>total)
		{
			a[0]++;
		}
		else
		{
			a[n]++;
		}
	}

	printf("the result of vote is :\n");
	for(n=0;n<total+1;n++)
	{
		if(n==0)
		  printf("the invalid vote is %d.\n",a[0]);
		else
		{
			printf("No.%d get %d votes.\n",n,a[n]);
		}
	}
}
