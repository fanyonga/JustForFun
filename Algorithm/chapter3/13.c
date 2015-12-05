#include<stdio.h>
/*
 *n 输入及格的学号
 *number 考试的总人数
 *total 考试学科的总个数
 *main() 统计并输出学科全部及格的学生的学号
 */

main()
{
	int n,total=3,number=9;
	int a[number+1];
	for(n=1;n<=number;n++)
	  a[n]=0;
	printf("请依次输入每门学科及格学生的学号(completed tag: -1) :\n");
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
		{
			break;
		}
		else
		{
			a[n]++;
		}
	}
	printf("考试学科全部及格的学生有 :\n");
	for(n=1;n<=number;n++)
	  if(a[n] == total )
		printf("%d ",n);
	printf("\n");
}
