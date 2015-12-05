#include<stdio.h>
#include<unistd.h>
/*
 *n 做游戏的人数
 *k 开始报号的人数编号
 *m 报编号为m的人退出圈内
 *main() 模拟n个小孩手拉手从第k的小孩开始报数（1-m），报m的小孩退出圈内并
 *		 继续报数的游戏
 */
main()
{
	int a[100],i,k,p,n,m,x;
	printf("input number of game :");
	scanf("%d",&n);
	printf("input serial number of game start : ");
	scanf("%d",&k);
	printf("input number of out_ring :");
	scanf("%d",&m);
	for(i=1;i<n;i++)
	  a[i]=1;
	p=0;
	k--;
	printf("wash out : \n");
	while(p<n-1)
	{
		sleep(1);
		x=0;
		while(x<m)
		{
			k++;
			if(k>n) k=1;
			x+=a[k];
		}
		printf("No.%2d child is out_ring.\n",k);
		a[k]=0;
		p++;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i] == 1)
		{
			printf("No.%2d is still in_ring.\n",i);
		}
	}
	printf("Game over!\n");
}
