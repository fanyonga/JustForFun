#include<stdio.h>
main()
{
 int i,n,sign;
 float s,t=1;
 printf("s=1/1!-1/3!+1/5!-...+(-1)n+1/(2n-1)!\n");
 printf("Please input the number of n:  ");
 scanf("%d",&n);
 s=1;
 sign=1;
 if(n > 1)
 {
	 for(i=2;i<=n;i++)
	 {
		 sign=-sign;
		 t=t*(2*i-2)*(2*i-1);
		 s+=sign/t;
	 }
 }
 printf("s=  %f\n",s);
}
