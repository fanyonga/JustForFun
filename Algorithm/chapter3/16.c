#include<stdio.h>
/*
 *设计一个正整数x，是的x^2为一个各位数字都不相同的数
 */

main()
{
	long x,y;
	int a[10];//define the number 0-9 appear time
	int i,count=0;
	printf("the result is:\n");
	for(y=10000;y<32000;y++)
	{
		x=y*y;
		for(i=0;i<10;i++)
		{
			a[i]=1;
		}
		for(i=1;i<10;i++)
		{
			if(a[x%10]==1)
			{
				a[x%10]=0;
			}
			else
			{
				break;
			}
			x/=10;
		}
		if(i == 10)
		{
			count++;
			printf("No.%4d: %ld ----- %ld\n",count,y,y*y);
		}
	}
	if(count == 0)
	{
		printf("no resolution!!!\n");
	}
}
