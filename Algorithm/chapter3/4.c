#include<stdio.h>
/*
 * n 图形的阶数
 * main（） 打印一个n阶的特殊三角形
 */
main()
{
	int a[100][100],n;
	int i,j,k=1;
	printf("Please input n :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			a[i+j][j]=k++;
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		  printf("%3d",a[i][j]);
		printf("\n");
	}

}
