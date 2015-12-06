#include<stdio.h>
/*
 *n 阵列的阶数,奇数
 *main()  构造并输出一个n阶魔方阵
 *6 1 8
 *7 5 3
 *2 9 4
 */
main()
{
	int i,j,i1,j1,x,n,a[100][100];
	printf("Input an odd integer :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		  a[i][j]=0;
	}
	i=0;
	j=n/2;
	x=1;
	while(x<=n*n)
	{
		a[i][j]=x++;
		i1=i--;
		j1=j--;
		if(i < 0) i=n-1;
		if(j < 0) j=n-1;
		if(a[i][j]!=0)
		{
			i=i1+1;
			j=j1;
		}
	}
	printf("This is your magic matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		  printf("%3d",a[i][j]);
		printf("\n");
	}
}
