#include<stdio.h>
/*
 *a[] 用于存储皇后的坐标（下标为行数，值为列数）
 *b[] 用于存储棋盘列的被占用情况
 *c[] 用于存储棋盘主对角线的被占用情况
 *d[] 用于存储棋盘负对角线的被占用情况
 *main() 递归搜索所有n皇后的情况并输出
 */

int a[20],b[20],c[40],d[40],n,t=0,k;

void output()
{
	for(k=1;k<=n;k++)
	{
		printf("%d,",a[k]);
	}
	printf("\nNo. %d \n",++t);
}

void try(int i)
{
	int j;
	for(j=1;j<=n;j++)
	{
		if(b[j]==0&&c[i+j]==0&&d[i-j+n]==0)
		{//判断是否所有对角线都没被占用
			a[i]=j;
			b[j]=c[i+j]=d[i-j+n]=1;
			if(i<n)
			{
				try(i+1);
			}
			else
			{
				output();
			}
			b[j]=c[i+j]=d[i-j+n]=0;
		}
	}
}
main()
{
	int i;
	printf("Please input the number of Queen:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		b[i]=0;
		c[i]=0;c[n+1]=0;
		d[i]=0;d[n+1]=0;
	}
	try(1);
}
