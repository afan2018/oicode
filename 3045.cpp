#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
queue<int>Q;
struct node{int to,nx,val;}edge[1000005],Edge[1000005];
struct Node{int fr,to,val;}w[1000005];
int dis[200005]={0},vis[200005]={0},st,ed,cnt=0,h[200005]={0},ncnt=0,nh[200005]={0},S[200005]={0},ins[200005]={0},bel[200005]={0},scc=0,top=0,sign=0,low[200005]={0},dfn[200005]={0},n,m;
void Add(int x,int y,int z)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt,edge[cnt].val=z;}
void NAdd(int x,int y,int z)
{Edge[++ncnt].to=y,Edge[ncnt].nx=nh[x],nh[x]=ncnt,Edge[ncnt].val=z;}
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
		int hh,maxx=0;
		do
		{
			hh=S[top--];
			bel[hh]=scc;
			ins[hh]=0;
		}
		while(hh!=x);
	}
}
void SPFA()
{
	vis[st]=1;
	Q.push(st);
	dis[st]=0;
	while(!Q.empty())
	{
		int fr=Q.front();
		vis[fr]=0;
		Q.pop();
		for(int i=nh[fr];i;i=Edge[i].nx)
		{
			int to=Edge[i].to;
			if(dis[to]>Edge[i].val+dis[fr])
			{
				dis[to]=Edge[i].val+dis[fr];
				if(!vis[to])
				{
					vis[to]=1;
					Q.push(to);
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		Add(x,y,z);
		w[i].fr=x,w[i].to=y,w[i].val=z;
	}
	Tarjan(1);
	for(int i=1;i<=m;i++)
		if(bel[w[i].fr]!=bel[w[i].to])
			NAdd(bel[w[i].fr],bel[w[i].to],w[i].val);
	memset(dis,0x3f,sizeof(dis));
	st=bel[1],ed=bel[n];
	SPFA();
	printf("%d",dis[ed]);
	return 0;
}