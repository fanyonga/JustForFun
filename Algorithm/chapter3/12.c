#include<stdio.h>
/*
 *n 输入的学生身高
 *a[i] 存储身高段的学生人数 149+i×5
 *main() 统计并输出每个学生身高段的人数
 */

main()
{
	int n,a[8];
	for(n=0;n<8;n++)
	  a[n]=0;
	printf("Please input height date in turn(completed tag : -1):\n");
	while(1)
	{
		scanf("%d",&n);
		if(n == -1)
		{
			break;
		}
		else if(n<150)
		{
			a[6]++;
		}
		else if(n>=180)
		{
			a[7]++;
		}
		else
		{
			a[(n-150)/5]++;
		}
	}
	printf("the result is:\n");
	for(n=0;n<8;n++)
	{
		if(n == 6)
		  printf("height<150 field the number of people is:%d\n",a[n]);
		else if(n == 7)
		  printf("height>179 field the number of people is:%d\n",a[n]);
		else
		  printf("%d<=height<=%d field the number of people is:%d\n",150+5*n, 154+5*n,a[n]);
	}
}
