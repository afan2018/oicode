#include<iostream>
using namespace std;
const int diry[]={1,2,2,1},dirx[]={2,1,-1,-2};
struct node{int x,y,t;}q[100000];
int n,m,ans=0,vis[1005][1005]={{0},{0}};
void BFS()
{
    int head=0,tail=1;
    q[1].x=0;
    q[1].y=0;
    q[1].t=0;
    vis[0][0]=1;
    while(head<=tail)
    {
        head++;
        for(int i=0;i<4;i++)
        {
            int tx=q[head].x+dirx[i];
            int ty=q[head].y+diry[i];
            if(tx>0&&tx<=n&&ty>0&&ty<=m&&!vis[tx][ty])
            {
                q[++tail].x=tx;
                q[tail].y=ty;
                q[tail].t=q[head].t+1;
                vis[tx][ty]=1;
                if(tx==n&&ty==m) {printf("%d",q[tail].t);return;}
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    BFS();
    return 0;
}
