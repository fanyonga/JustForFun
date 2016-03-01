#include<stdio.h>
/*
 *a[100][3] 采用数组的方式存储三色花的排列
 *n 红蓝黄花的组数
 *main 输入一定序列的三色花排列顺序，以最小的交换次数讲所有的花排列为红蓝黄
 */
main()
{
	int a[100][3];
	int swapCount=0;
	int n;
	int i,j,k;
	printf("Please input the number of group flower:\n");
	scanf("%d",&n);
	printf("Input the order of flower(0,1,2):\n");
	for(i=0;i<n;i++)
	  for(j=0;j<3;j++)
		scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
	{
		if(a[i][0]==1)
		{
			for(j=0;j<n;j++)
			{
				if(a[j][1]==0)
				{
					int temp=a[i][0];
					a[i][0]=a[j][1];
					a[j][1]=temp;
					swapCount+=3;
					break;
				}
			}
		}
		if(a[i][0]==2)
		{
			for(j=0;i<n;j++)
			{
				if(a[j][2]==0)
				{
					int temp=a[i][0];
					a[i][0]=a[j][2];
					a[j][2]=temp;
					swapCount+=3;
					break;
				}
			}
		}
		if(a[i][1]==2)
		{
			for(j=0;j<n;j++)
			{
				if(a[j][2]==1)
				{
					int temp=a[i][1];
					a[i][1]=a[j][2];
					a[j][2]=temp;
					swapCount+=3;
					break;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(a[i][0]==1)
		{
			for(j=0;j<n;j++)
			{
				if(a[j][1]==2)
				{
					for(k=0;k<n;k++)
					{
						if(a[k][2]==0)
						{
							int temp=a[i][0];
							a[i][0]=a[j][1];
							a[j][1]=a[k][2];
							a[k][2]=temp;
							swapCount+=4;
							break;
						}
					}
				}
			}
		}
		if(a[i][0]==2)
		{
			for(j=0;j<n;j++)
			{
				if(a[j][1]==0)
				{
					for(k=0;k<n;k++)
					if(a[k][2]==1)
					{
						int temp=a[i][0];
						a[i][0]=a[j][1];
						a[j][1]=a[k][2];
						a[k][2]=temp;
						swapCount+=3;
						break;
					}
						
				}
			}
		}
	}

	printf("SwapCount: %d \n",swapCount);
	for(i=0;i<n;i++)
	{
	  for(j=0;j<3;j++)
		printf("%d	",a[i][j]);
	  printf("\n");
	}

}
