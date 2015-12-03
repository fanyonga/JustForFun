#include<stdio.h>

/*
 *n 正整数 表示一共有n位自然数
 *r 正整数，表示在n位自然数任取r位不相同的自然数
 *main() 输出n的r排列
 */
int a[100];

void f(int n,int r)
{
	int i,j;
	for(i=n;i>=r;i--)
	{
		a[r]=i;
		if(r>1)
		{
			f(i-1,r-1);
		}
		else
		{
			for(j=a[0];j>0;j--)
			  printf("%d  ",a[j]);
			printf("\n");
		}
	}
}


main()
{
	int n,r;
	printf("Please input n,r(n,r->Z+&&n>=r) :");
	scanf("%d%d",&n,&r);
	printf("All arrange is as list:\n");
	a[0]=r;
	f(n,r);
	printf("\n");
}
