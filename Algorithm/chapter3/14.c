#include<stdio.h>
#include<string.h>
/*
 *n 一个长整数
 *main() 输出n的数字的英文排列
 */
char eng[10][6]={"zero","one","two","three","four","five","six","seven","eight","nine"};
/*void f(long n)
{
	if(n<10)
	  printf("%s",eng[n]);
	else
	{
		f(n/10);
		printf("-%s",eng[n%10]);
	}
}
main()
{
	long n;
	printf("Please input a long number(n>0&&n->Z+): ");
	scanf("%ld",&n);
	printf("the English list is:\n");
	f(n);
	printf("\n");
}*/


main()
{
	char n[100];
	int i,len;
	printf("Please input a long number(n->Z+):");
	scanf("%s",n);
	len=strlen(n);
	printf("the English list is:\n");
	if(len == 0)
	{
		printf("input error!\n");
	}
	else
	{
		printf("%s",eng[n[0]-48]);
		for(i=1;i<len;i++)
		  printf("-%s",eng[n[i]-48]);
	}
	printf("\n");
}
