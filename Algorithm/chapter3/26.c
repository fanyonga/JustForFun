#include<stdio.h>
/*
 *n 灯或同学的个数
 *main() 处理并输出开灯问题
 */

main()
{
	int i,j;
	int n,count=0;
	int a[100];
	printf("Please input the number of light: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  a[i]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j*i<=n;j++)
		  a[j*i]=1-a[j*i];
	}
	for(i=1;i<=n;i++)
	  count+=a[i];
	printf("The light is lighting : %d\n",count);
}
