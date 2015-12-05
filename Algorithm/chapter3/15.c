#include<stdio.h>
/*
 *x 顾客要买的商品总价值
 *y 顾客交给售货员的钱,作为计数器
 *main() 输出售货员找给顾客的钱张数最小的方案
 */

main()
{
	int a[7]={0,50,20,10,5,2,1},b[7];
	int x,y;
	for(y=1;y<7;y++)
	  b[y]=0;
	printf("Please input the value of goods and guest give the money: \n");
	scanf("%d%d",&y,&x);
	x-=y;//the total of charges
	for(y=1;y<7;y++)
	{
		b[y]=x/a[y];
		x=x%a[y];
	}
	printf("the salesman should give charges:\n");
	for(y=1;y<7;y++)
	  if(b[y] != 0)
	  {
		  printf("%2d-----%d\n",a[y],b[y]);
	  }
}
