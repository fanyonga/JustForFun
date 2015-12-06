#include<stdio.h>
/*
 *n 矩阵的阶数
 *main() 利用二维数组打印n阶趣味矩阵,如下
 *0 1 1 1 0
 *2 0 1 0 4
 *2 2 0 4 4
 *2 0 3 0 4
 *0 3 3 3 0
 */

main()
{
	int i,j,n,a[100][100];
	printf("Please input the matrix of n(n>=3)\n:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j || i+j==n-1) a[i][j]=0;
			else if(i>j && i+j<n-1) a[i][j]=2;
			else if(j>i && i+j<n-1) a[i][j]=1;
			else if(j>i && i+j>n-1) a[i][j]=4;
			else a[i][j]=3;
		}
	}
	printf("This your interesting matrix :\n");
	for(i=0;i<n;i++)
	{
	  for(j=0;j<n;j++)
		printf("%d ",a[i][j]);
	  printf("\n");
	}
}
