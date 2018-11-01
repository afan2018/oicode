#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
struct node{int nx,to,val;}edge[200005];
int h[20005]={0},cnt=0,n,m,vis[10005]={0},dis[10005]={0};
void Add(int x,int y,int z)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt,edge[cnt].val=z;}
void DFS(int x)
{
    vis[x]=1;
    for(int i=h[x];i;i=edge[i].nx)
    {
        int to=edge[i].to;
        if(dis[x]+edge[i].val<dis[to])
        {
            if(vis[to]) {cout<<"No";exit(0);}
            dis[to]=dis[x]+edge[i].val;
            DFS(to);
        }
    }
}
int main()
{
    memset(dis,0x7f,sizeof(dis));
    cin>>n>>m;
    for(int i=1,fl,x,y,z;i<=m;i++)
    {
        cin>>fl;
        switch(fl)
        {
            case 1:cin>>x>>y>>z;Add(x,y,-z);break;
            case 2:cin>>x>>y>>z;Add(y,x,z);break;
            case 3:cin>>x>>y;Add(x,y,0);Add(y,x,0);break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        DFS(i);
    }
    cout<<"Yes";
    return 0;
}
