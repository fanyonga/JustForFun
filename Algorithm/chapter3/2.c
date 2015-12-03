#include<stdio.h>
#include<math.h>

void check(int i)
{
	int a[100],x,y,sum=1;
	int count=1;
	a[0]=1;
	x=i;
	for(y=2;y<x;y++)
	{
		if(i%y==0)
		{
			sum+=y;
			a[count++]=y;
		}
	}
	if(sum == i)
	{
		printf("%d its factors are ",i);
		for(y=0;y<count-1;y++)
		  printf("%d ,",a[y]);
		printf("%d  .\n",a[count-1]);

	}
}

main()
{
  int i,n;
  printf("search the completed number in 2 to n.\n");
  printf("Please input the number of n   :");
  scanf("%d",&n);
  for(i=2;i<=n;i++)
  {
	  check(i);
  }
}
