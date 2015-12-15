#include<stdio.h>
/*
 *maze 二位数组，用于存储迷宫方位的信息：1---有障碍 0----可通行 3---已走过
 *	   2---死胡同
 *main（） 运用图的深度优先算法搜索迷宫（0,0）到（7,7）的可行路径`
 */

int maze[8][8]={{0,0,0,0,0,0,0,0},{0,1,1,1,1,0,1,0},{0,0,0,0,1,0,1,0},
        {0,1,0,0,0,0,1,0},{0,1,0,1,1,0,1,0},{0,1,0,0,0,0,1,1},{0,1,0,0,1,0,0,0},
      {0,1,1,1,1,1,1,0}};
int fx[4]={1,-1,0,0},fy[4]={0,0,1,-1};

int i,j,k,total;

bool check(int i,int j)
{//判断（i,j)坐标是否可行
    if(i<0||i>7||j<0||j>7)
        return false;
    if(maze[i][j]!=0)
        return false;
    return true;
}

void Out()
{
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(maze[i][j]==3)
			{
				printf("V ");
				total++;
			}
			else
			{
				printf("* ");
			}
		}
		printf("\n");
	}
	printf("Total pace: %d\n",total);
}
void search(int i,int j)
{
    int k,newi,newj;
    for(k=3;k>=0;k--)
    {
        if(check(i+fx[k],j+fy[k]))
		{
			newi=i+fx[k];
			newj=j+fy[k];
			maze[newi][newj]=3;
			if(newi==7&&newj==7)
			{
				printf("This is your map:\n");
				Out();

			}
			else
			{
				search(newi,newj);
			}
		}
	}
	maze[i][j]=2 ;
}
main()
{
	total=0;
	maze[0][0]=3;
	search(0,0);
}
