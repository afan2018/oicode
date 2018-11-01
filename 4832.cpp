#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int to,nx;}edge[100005];
struct newnode{int to,nx;}nedge[100005];
int vis[100005]={0},n,m,anss[100005]={0},maxx[100005]={0},h[100005]={0},nh[100005]={0},ncnt=0,cnt=0,ans[100005]={0},dfn[100005]={0},stack[100005]={0},ins[100005]={0},bel[100005]={0},scc=0,low[100005]={0},top=0,sign=0;
void Add(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
void NAdd(int x,int y)
{nedge[++ncnt].to=y,nedge[ncnt].nx=nh[x];nh[x]=ncnt;}
int DFS(int x)
{
	vis[x]=1;
	if(ans[x]) return ans[x];
	ans[x]=maxx[x];
	for(int i=nh[x];i;i=nedge[i].nx)
	{
		int to=nedge[i].to;
		ans[x]=max(ans[x],DFS(to));
	}
	return ans[x];
}
void Tarjan(int x)
{
	stack[++top]=x;
	ins[x]=1;
	dfn[x]=low[x]=++sign;
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
	if(low[x]==dfn[x])
	{
		scc++;
		int hh;
		do
		{
			hh=stack[top--];
			bel[hh]=scc;
			ins[hh]=0;
			maxx[scc]=max(hh,maxx[scc]);
		}
		while(hh!=x);
	}
}
void Build()
{
	for(int i=1;i<=n;i++)
		for(int j=h[i];j;j=edge[j].nx)
		{
			int to=edge[j].to;
			if(bel[to]!=bel[i])
				NAdd(bel[i],bel[to]);
		}
}
int main()
{
//	freopen("graph.in","r",stdin);
//	freopen("graph.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)
	{
		cin>>x>>y;
		Add(x,y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			Tarjan(i);
	Build();
	for(int i=1;i<=scc;i++)
	{
		if(!vis[i])
			DFS(i);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[bel[i]]<<' ';
	return 0;
}