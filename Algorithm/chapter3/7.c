#include<stdio.h>
/*
 * n 输入的任意十进制正整数
 * main()  递归从低位到高位依次输出数字
 */
void f(int n)
{
	if(n == 0) return;
	else
	{
		printf("%d ",n%10);
		f(n/10);
	}
}

main()
{
	int n;
	printf("Please input n（n>0&&n->Z): ");
	scanf("%d",&n);
	printf("the ascending order is :\n");
	/*while(n != 0)
	{
		printf("%d  ",n%10);
		n=n/10;
	}*/

	f(n);

	printf("\n");
}
