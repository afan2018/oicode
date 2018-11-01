#include<iostream>
#include<queue>
using namespace std;
struct node{int to,nx;}edge[1000005],nedge[1000005];
int ans=0,cnt=0,ncnt=0,n,m,val[100005]={0},maxx[100005]={0},minn[100005]={0},h[1000005]={0},nh[1000005]={0},vis[100005]={0};
queue<int>Q;
inline void Add(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
inline void NAdd(int x,int y)
{nedge[++ncnt].to=y,nedge[ncnt].nx=nh[x],nh[x]=ncnt;}
void SPFA(int v0,node w[],int tab[],int fl)
{
    fill(vis+1,vis+n+1,0);
    while(!Q.empty()) Q.pop();
    vis[v0]=1;
    Q.push(v0);
    if(fl==1) minn[1]=val[v0];
    else maxx[1]=val[v0];
    while(!Q.empty())
    {
        int fr=Q.front();
        Q.pop();
        for(int i=tab[fr];i;i=w[i].nx)
        {
            int to=w[i].to;
            if(!vis[to])
            {
                vis[to]=1;
                Q.push(to);
            }
            if(fl==1) minn[to]=min(minn[fr],val[to]);
            else maxx[to]=max(maxx[fr],val[to]);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&val[i]);
    for(int i=1,x,y,z;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        Add(x,y);
        NAdd(y,x);
        if(z==2)
        {
            Add(y,x);
            NAdd(x,y);
        }
    }
    fill(maxx+1,maxx+n+1,0);
    fill(minn+1,minn+n+1,0x3f3f3f3f);
    SPFA(1,edge,h,1);
    SPFA(n,nedge,nh,2);
    for(int i=1;i<=n;i++)
        ans=max(ans,maxx[i]-minn[i]);
    printf("%d\n",ans);
    return 0;
}
