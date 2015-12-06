#include<stdio.h>
/*
 *n 方阵的阶数
 *mian() 利用二维数组构造并输出一个n阶螺旋方阵,如
 *1 8 7
 *2 9 6
 *3 4 5
 */

main()
{
	int i,j,k,n,x,y,t;
	int a[100][100];
	int b[2];
	printf("Input the matrix of n(n->Z+) :\n");
	scanf("%d",&n);
	b[0]=0;
	b[1]=1;
	k=n;
	t=1;
	x=1;
	while(x<=n*n)
	{
		for(y=1;y<=2*k-1;y++)
		{
			b[y/(k+1)]=b[y/(k+1)]+t;
			a[b[0]][b[1]]=x++;
		}
		k--;
		t=-t;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		  printf("%3d ",a[i][j]);
		printf("\n");
	}
}
