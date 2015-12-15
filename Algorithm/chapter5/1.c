#include<stdio.h>
/*
 *jz 二位数组，用于储存城市A-H之间能否相互到达：1---能 0----不能
 *sq 结构体数组，用于存储访问城市的顺序
 *visited 用于存储当前下标城市的访问情况： 1---已访问 0---未访问
 *main（） 运用图的广度优先算法搜索`城市A-H之间的最短路径`
 */
int jz[8][8]={{0,1,1,1,0,1,0,0},{1,0,0,0,0,1,0,0},{1,0,0,1,1,0,0,0},
      {1,0,1,0,0,0,1,0},{0,0,1,0,0,0,1,1},{1,1,0,0,0,0,0,1},{0,0,0,1,1,0,0,1},
      {0,0,0,0,1,1,1,0}};
struct {
  int city,pre;
}sq[100];

int qh,qe,i,visited[100];

void out()
{
  printf("城市A到城市H最短路径如下:\n");
  printf("%d",sq[qe].city);
  while (sq[qe].pre!=0) {
    qe=sq[qe].pre;
    printf("--%d",sq[qe].city);
  }
  printf("\n");
}

void search()
{
  qh=0;
  qe=1;
  sq[1].city=1;
  sq[1].pre=0;
  visited[1]=1;
  while (qh!=qe)
  {
    qh++;
    for (i=1; i<=8;i++)
    {
        if(jz[sq[qh].city-1][i-1]==1&& visited[i]==0)
        {
          qe++;
          sq[qe].city=i;
          sq[qe].pre=qh;
          visited[i]=1;
          if(sq[qe].city==8)
          {
            out();
            return;
          }
        }
    }
  }
  printf("Non solution\n");
}

int main(int argc, char const *argv[]) {
  int i,n=8;
  for(i=1;i<=n;i++)
  {
    visited[i]=0;
  }
  search();
  return 0;
}
