#include<stdio.h>
/*
 *n  十进制的正整数
 *main()  递归从高位到低位输出n的每一位整数
 */

void f(n)
{
	if(n == 0) return;
	else
	{
		f(n/10);
		printf("%d ",n%10);
	}
}


main()
{
	int n;
	printf("Please input n(n->Z+) ：");
	scanf("%d",&n);
	printf("the descending order is :\n");
	f(n);
	printf("\n");
}
