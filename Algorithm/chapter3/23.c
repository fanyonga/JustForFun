#include<stdio.h>
/*
 *n 输入有限个0-9之间的数字
 *main 统计并输出链环数字的出现次数
 */

main()
{
	int n,i,j;
	int a[10][10];
	int result=0;
	printf("Input a series of number:(0<=n<=9),please use -1 as the end;:\n");
	int front=-1;
	for(i=0;i<10;i++)
	  for(j=0;j<10;j++)
		a[i][j]=0;
	while(1)
	{
		scanf("%d",&n);
		if(n == -1) break;
		if(front!=-1)
		{
			a[front][n]++;
		}
		front=n;
	}
	printf("The time of the numbers appears is :\n");
	for(i=0;i<10;i++)
	{
		for(j=i;j<10;j++)
		{
			if(a[i][j]>0&&a[j][i]>0)
			{
			  
			  if(i==j&a[i][j]<=1) break;
			  result=1;
			  printf("(%d,%d)=%d ",i,j,a[i][j]);
			  if(i==j&&a[i][j]>1)
			  {
				  printf("\n");
				  continue;
			  }
			  printf("(%d,%d)=%d\n",j,i,a[j][i]);
			}
		}
	}
	if(result==0)
	  printf("Non resolution!\n");
}
