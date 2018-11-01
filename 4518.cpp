#include<iostream>
using namespace std;
struct node{int to,nx;}edge[200005];
int sign=0,ans=0x3f3f3f3f,h[200005]={0},n,cnt=0,stack[200005]={0},ins[200005]={0},top=0,bel[200005]={0},low[200005]={0},dfn[200005]={0},scc=0,ccnt[200005]={0};
inline void Add(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
void Tarjan(int x)
{
    dfn[x]=low[x]=++sign;
    stack[++top]=x;
    ins[x]=1;
    for(int i=h[x];i;i=edge[i].nx)
    {
        int to=edge[i].to;
        if(!dfn[to])
        {
            Tarjan(to);
            low[x]=min(low[x],low[to]);
        }
        else if(ins[to]) low[x]=min(low[x],dfn[to]);
    }
    if(dfn[x]==low[x])
    {
        scc++;
        int hh;
        do
        {
            hh=stack[top--];
            ins[hh]=0;
            bel[hh]=scc;
            ccnt[scc]++;
        }
        while(hh!=x);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++)
    {
        scanf("%d",&x);
        Add(i,x);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) Tarjan(i);
    for(int i=1;i<=scc;i++)
        if(ccnt[i]!=1)
            ans=min(ans,ccnt[i]);
    printf("%d",ans);
    return 0;
}
