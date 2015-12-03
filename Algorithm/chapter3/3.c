#include<stdio.h>
/*
 * n 行数
 * m 列数
 * main（） 输出一个n×m的矩阵的鞍点
 */
void input(int a[][100],int n,int m)
{
	int i,j;
	printf("Please input the %d*%d matric in order:\n",n,m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}


void output(int a[][100],int n,int m)
{
	int i,j;
	printf("Now the %d*%d matric in order is output:\n",n,m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%4d ",a[i][j]);
		}
		printf("\n");
	}
}
main()
{
	int a[100][100],n,m;
	int i,j,result=0;
	int minj,max;
	printf("Please input n*m matric :n  m  \n(n,m<100)");
	scanf("%d %d",&n,&m);
	input(a,n,m);
	output(a,n,m);
	for(i=0;i<n;i++)
	{
		max=a[i][0];
		minj=0;
		for(j=1;j<m;j++)
		{
			if(max>a[i][j])
			{
				max=a[i][j];
				minj=j;
			}
		}
		for(j=0;j<n;j++)
		{
			if(max<a[j][minj]) break;
		}

		if( j == n)
		{
			printf("the result is a[ %d ][ %d ] =%d\n",i,minj,max);
			result=1;
		}

	}

	if(result == 0)
	{
		printf("No solution!\n");
	}
}
