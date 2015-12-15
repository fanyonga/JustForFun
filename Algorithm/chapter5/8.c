#include<stdio.h>
#include<math.h>
/*
 *a[] 用于存储20个数的排列
 *main() 把从1到20这20个数摆成一个环，要求相邻的两个数的和是一个素数
 */
int a[21];
int count=0;//种类

int check1(int k,int i)//判断数k是否被用过：1-没有，否则为0
{
	int j;
	for(j=1;j<i;j++)
	  if(k == a[j])
		return 0;
	return 1;
}

int check2(int k)//判断k是否为质数
{
	int i;
	for(i=2;i<k;i++)
	{
		if(k%i==0) return 0;
	}
	return 1;
}

int check3(int k,int i)//判断k的两侧是否为质数
{
	if(i<20)
	  return check2(k+a[i-1]);
	else
	  return check2(k+a[1])+check2(k+a[i-1])-1;
}

void output()
{
	int i;
	for(i=1;i<=20;i++)
	  printf("%d ",a[i]);
	printf("\n");
	count++;
}

void try(int i)
{
	int k;
	for(k=2;k<=20;k++)
	{
		if(check1(k,i)==1&&check3(k,i)==1)
		{
			a[i]=k;
			if(i==20)
			{
				output();
			}
			else
			{
				try(i+1);
			    a[i]=0;
			}
		}
	}
}

main()
{
	int i;
	for(i=1;i<=20;i++)
	  a[i]=0;
	a[1]=1;
	try(2);
	if(count == 0)
	  printf("Non solution!\n");
	else
	  printf("Total kind: %d\n",count);
}
