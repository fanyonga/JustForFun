#include<stdio.h>

/*
 *n 一个十进制的正整数
 *main() 递归输出n的2进制组成式
 */
void f(int n,int r)
{
	if(n == 0) return;
	else
	{
		f(n/2,r+1);
		if(n%2 == 1)
		{
			printf("2^%d",r);
			if(r>0)
			  printf("+");
		}
	}
}

main()
{
	int n;
	printf("Please input n(n->Z+):  ");
	scanf("%d",&n);
	printf("the number can be used like this: \n%d = ",n);
	f(n,0);
	printf("\n");
}
