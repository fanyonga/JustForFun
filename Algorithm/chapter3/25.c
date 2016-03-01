#include<stdio.h>
/*
 *num 及格人数
 *main 统计一场考试50个人中有不少于3门成绩不低于90的人数
 */

main()
{
	int i,j;
	int num=0;
	int point;
	for(i=0;i<5;i++)
	{
		int tag=0;
		for(j=0;j<5;j++)
		{
			scanf("%d",&point);
			tag+=point/90;
		}
		num+=tag/3;
	}
	printf("Num:  %d\n",num);
}
