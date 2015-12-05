#include<stdio.h>
#include<string.h>
/*
 *n 高精度的正整数
 *m 长正整数
 *main() 输出n×m的结果
 */

main()
{
	char n[100];
	int a[256];
	int len,up,i;
	long m,temp;
	printf("input a great number:\n");
	scanf("%s",n);
	printf("input a long integer number：\n");
	scanf("%ld",&m);
	len=strlen(n);
	up=0;
	for(i=0;i<len;i++)
	{
		temp=(n[len-1-i]-48)*m+up;
		a[i]=temp%10;
		up=temp/10;
	}
	while(up!=0)
	{
		a[i++]=up%10;
		up/=10;
	}
	for(i--;i>=0;i--)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}
