#include<stdio.h>
#include<stdlib.h>
bool check(int a[],int n)
{
    int i;
    for(i=1;i<=n-1;i++)
    {
        if(abs(a[i]-a[n]) == abs(i-n)||(a[i] == a[n]))
        {
            return false;
        }

    }
    return true;
}

int main()
{
    int a[9],i,j,sum=0;
    for(a[1]=1;a[1]<=8;a[1]++)
    {
        for(a[2]=1;a[2]<=8;a[2]++)
        {
            if(!check(a,2)) continue;
            for(a[3]=1;a[3]<=8;a[3]++)
            {
                if(!check(a,3)) continue;
                for(a[4]=1;a[4]<=8;a[4]++)
                {
                    if(!check(a,4)) continue;
                    for(a[5]=1;a[5]<=8;a[5]++)
                    {
                        if(!check(a,5)) continue;
                        for(a[6]=1;a[6]<=8;a[6]++)
                        {
                            if(!check(a,6)) continue;
                            for(a[7]=1;a[7]<=8;a[7]++)
                            {
                                if(!check(a,7)) continue;
                                for(a[8]=1;a[8]<=8;a[8]++)
                                {
                                    if(!check(a,8)) continue;
                                    else
                                    {
										for(i=1;i<=8;i++)
										  printf("%d ",a[i]);
										printf("\n");
                                        sum++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("complited!!Toal::%d",sum);
    return 0;
}
