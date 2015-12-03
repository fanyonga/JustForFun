#include<stdio.h>
/*
 * n 输入的整数
 * main() 输出整数n的所有规划式总数量
 */
int divinteger(int m,int n)
{
	if(m == 1 || n == 1)
	{
		return 1;
	}
	else if(m<n)
	{
		return divinteger(m,m);
	}
	else if(m == n)
	{
		return 1+divinteger(m,m-1);
	}
	else
	{
		return divinteger(m,n-1)+divinteger(m-n,n);
	}
}
main()
{
	int n;
	printf("Please input n(1>0):  ");
	scanf("%d",&n);
	printf("the total of number divinteger:  %d \n",divinteger(n,n));
}
