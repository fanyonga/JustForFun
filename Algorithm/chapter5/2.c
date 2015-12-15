#include<stdio.h>
/*
 *maze 二位数组，用于存储迷宫方位的信息：1---有障碍 0----可通行 -1---已走过
 *sq 结构体数组，用于存储走迷宫的的顺序
 *main（） 运用图的广度优先算法搜索迷宫（0,0）到（7,7）的可行路径`
 */

int maze[8][8]={{0,0,0,0,0,0,0,0},{0,1,1,1,1,0,1,0},{0,0,0,0,1,0,1,0},
        {0,1,0,0,0,0,1,0},{0,1,0,1,1,0,1,0},{0,1,0,0,0,0,1,1},{0,1,0,0,1,0,0,0},
      {0,1,1,1,1,1,1,0}};
int fx[4]={1,-1,0,0},fy[4]={0,0,1,-1};

struct{
  int x,y,pre;
}sq[100];

int i,j,k,qe,qh;

void out(int qe)
{//递归输出走迷宫的路径
    if(sq[qe].pre==-1)
    {
        printf("(%d ,%d )",sq[qe].x,sq[qe].y);
        return;
    }
    out(sq[qe].pre);
    printf("---(%d ,%d )",sq[qe].x,sq[qe].y);
}

bool check(int i,int j)
{//判断（i,j)坐标是否可行
    if(i<0||i>7||j<0||j>7)
        return false;
    if(maze[i][j]==1 || maze[i][j]==-1)
        return false;
    return true;
}
void search()
{
    qh=-1;//用来存储前一个位置的sq下标，为-1时表示起点
    /*初始化起点*/
    qe=0;
    maze[0][0]=-1;
    sq[0].pre=-1;
    sq[0].x=0;
    sq[0].y=0;
    /*开始搜索*/
    while(qh!=qe)
    {
        qh++;
        for(k=0;k<4;k++)
        {
            i=sq[qh].x+fx[k];
            j=sq[qh].y+fy[k];
            if(check(i,j))
            {
                qe++;
                sq[qe].x=i;
                sq[qe].y=j;
                sq[qe].pre=qh;
                maze[i][j]=-1;
                if(sq[qe].x==7&& sq[qe].y==7)/*到达终点则退出搜索*/
                {
                    printf("走迷宫的路径为:\n");
                    out(qe);
                    printf("\n");
                }
            }
        }
    }
    printf("Non solution\n");
}

main()
{
    search();
}
