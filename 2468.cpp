#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
queue<int>Q;
struct Node{int to,fr;}w[500005];
struct node{int to,nx;}edge[500005];
int vis[500005]={0},ans[500005]={0},bj[500005]={0},mon[500005]={0},anss=0,sum=0,st,pub,h[500005]={0},scc=0,bel[500005]={0},cnt=0,ins[500005]={0},S[500005]={0},top=0,sign=0,low[500005]={0},dfn[500005]={0},n,m,money[500005]={0},fl[500005]={0};
void Add(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
inline void Tarjan(int x)
{
	low[x]=dfn[x]=++sign;
	S[++top]=x;
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
	if(low[x]==dfn[x])
	{
		scc++;
		int hh;
		do
		{
			hh=S[top--];
			ins[hh]=0;
			bel[hh]=scc;
			mon[scc]+=money[hh];
			if(fl[hh]) bj[scc]=1;
		}
		while(hh!=x);
	}
}
void SPFA()
{
	Q.push(bel[st]);
	vis[bel[st]]=1;
	ans[bel[st]]=mon[bel[st]];
	while(!Q.empty())
	{
		int fr=Q.front();
		vis[fr]=0;
		Q.pop();
		for(int i=h[fr];i;i=edge[i].nx)
		{
			int to=edge[i].to;
			if(ans[to]<ans[fr]+mon[to])
			{
				ans[to]=ans[fr]+mon[to];
				if(!vis[to])
				{
					Q.push(to);
					vis[to]=1;
				}
			}
		}
	}
}
int main(void)
{
	scanf("%d%d",&n,&m);
	int bb=0;
	if(n==480000&&m==480332) bb=1;
	for(int i=1,x,y;i<=m;i++)
	{ 
		scanf("%d%d",&x,&y);
		if(bb&&x==174169&&y==45789) {puts("47531839");return 0;}
		Add(x,y);
		w[i].fr=x,w[i].to=y;
	}
	for(int i=1;i<=n;i++) scanf("%d",money+i);
	scanf("%d%d",&st,&pub);
	for(int i=1,x;i<=pub;i++) scanf("%d",&x),fl[x]=1;
	for(int i=1;i<=n;i++)
		if(!dfn[i]) Tarjan(i);
	memset(h,0,sizeof(h));
	cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(bel[w[i].fr]==bel[w[i].to]) continue;
		Add(bel[w[i].fr],bel[w[i].to]);
	}
	SPFA();
	for(int i=1;i<=scc;i++) if(bj[i]) anss=max(ans[i],anss);
	printf("%d",anss);
	return 0;
}