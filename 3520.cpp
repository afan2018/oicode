#include<iostream>
#include<queue>
#include<cstring>
#include<ctime>
#include<cstdlib>
using namespace std;
queue<int>Q;
struct node{int to,nx,val;}edge[40005];
int n,m,s,h[40005]={0},cnt=0,path[205]={0},vis[205]={0},dis[205]={0};
double P[205][205]={{0},{0}},dp[205][205]={{0},{0}};
inline void Add(int x,int y,int z)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt,edge[cnt].val=z;}
void SPFA()
{
    memset(dis,0x3f,sizeof(dis));
    Q.push(1);
    vis[1]=1;
    dis[1]=0;
    while(!Q.empty())
    {
        int fr=Q.front();
        vis[fr]=0;
        Q.pop();
        for(int i=h[fr];i;i=edge[i].nx)
        {
            int to=edge[i].to;
            if(dis[to]>dis[fr]+edge[i].val)
            {
                dis[to]=dis[fr]+edge[i].val;
                path[to]=fr;
                if(!vis[to])
                {
                    vis[to]=1;
                    Q.push(to);
                }
            }
        }
    }
}
void DP(int x,int fa)
{
    int son=0;
    for(int i=h[x];i;i=edge[i].nx)
        son+=(edge[i].to!=fa);
    if(!son)
    {
        for(int i=1;i<=s;i++)
            dp[x][i]=P[x][i];
        return;
    }
    for(int i=h[x];i;i=edge[i].nx)
    {
        int to=edge[i].to;
        if(to!=fa)
        {
            DP(to,x);
            for(int j=s;j>=0;j--)
                for(int k=j;k>=0;k--)
                    dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[to][k]);
        }
    }
    for(int i=s;i>=0;i--)
    {
        dp[x][i]/=son;
        for(int j=i;j>=0;j--)
            dp[x][i]=max(dp[x][i],P[x][j]+dp[x][i-j]*(1-P[x][j])/son);
    }
}
int main()
{
    srand(time(NULL));
    scanf("%d%d",&n,&m);
    for(int i=1,x,y,z;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        Add(x,y,z);
        Add(y,x,z);
    }
    SPFA();
    scanf("%d",&s);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=s;j++)
            scanf("%lf",&P[i][j]);
    memset(h,0,sizeof(h));
    cnt=0;
    for(int i=2;i<=n;i++)
    {
        Add(i,path[i],rand());
        Add(path[i],i,rand());
    }
    DP(1,0);
    printf("%.4lf",dp[1][s]);
    return 0;
}