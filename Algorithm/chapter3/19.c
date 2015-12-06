#include<stdio.h>
#include<math.h>
/*
 *n 小于100的正整数
 *main() 计算并输出高精度数n!
 * 斯特林公式 求出n!的位数
 */
main()
{
	long a[256],b,d;
	int m,n,i,j,r;
	printf("Input an integer n(n>0&&n<100)");
	scanf("%d",&n);
	m=(int)(log(n)*n/6)+2;
	printf("m:%d\n",m);
	a[1]=1;
	for(i=2;i<=m;i++)
		a[i]=0;
	d=0;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			b=a[j]*i+d;
			a[j]=b%1000000;
			d=b/1000000;
		}
		if(d != 0)
		{
			a[j]=d;
		}
	}
	for(i=m;i>=1;i--)
	{
		if(a[i] == 0) continue;
		else
		{
			r=i;
			break;
		}
	}
	printf("%d! =  \n",n);
	printf("%6ld ",a[r]);
	d=1;
	for(i=r-1;i>=1;i--)
	{
		if(d%5 == 0) printf("\n");
		d++;

		if(a[i]>99999)
		  printf("%ld ",a[i]);
		else if(a[i]>9999)
		  printf("0%ld ",a[i]);
		else if(a[i]>999)
		  printf("00%ld ",a[i]);
		else if(a[i]>99)
		  printf("000%ld ",a[i]);
		else if(a[i]>9)
		  printf("0000%ld ",a[i]);
		else
		  printf("00000%ld ",a[i]);
	}
}
