#include<iostream>
#include<cstring>
using namespace std;
struct node{int to,nx,val;}edge[50005];
int cnt=0,h[50005]={0},n,k,m,st,ed,rej[105][105]={0},cil[1005]={0},vis[1005]={0},ans=0x7f7f7f7f,fl=0,opp[1005]={0};
void Add(int x,int y,int z)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt,edge[cnt].val=z;}
void DFS(int v,int sum)
{
    if(sum>=ans) return;
    //cout<<v<<endl;
    if(v==st) {fl=1;ans=min(ans,sum);return;}
    int tmp[1005]={0};
    memcpy(tmp,opp,sizeof(tmp));
    vis[v]=1;
    for(int i=1;i<=k;i++)
        if(rej[cil[v]][i])
            opp[i]=1;
    for(int i=h[v];i;i=edge[i].nx)
    {
        int to=edge[i].to;
        if(opp[cil[to]]||vis[to]) continue;
        DFS(to,sum+edge[i].val);
    }
    memcpy(opp,tmp,sizeof(tmp));
}
int main()
{
    scanf("%d%d%d%d%d",&n,&k,&m,&st,&ed);
    for(int i=1;i<=n;i++)
        scanf("%d",&cil[i]);
    for(int i=1;i<=k;i++)
        for(int j=1;j<=k;j++)
            scanf("%d",&rej[i][j]);
    for(int i=1,x,y,z;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        Add(x,y,z);
        Add(y,x,z);
    }
    DFS(ed,0);
    if(!fl) puts("-1");
    else printf("%d",ans);
    return 0;
}
