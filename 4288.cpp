#include<iostream>
#include<iomanip>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
queue<int>Q;
struct node{int to,nx;}edge[200005];
struct edon{int to,nx;}Edge[200005];
int n,m,h[200005]={0},cnt=0,h0[200005]={0},cnt0=0,st,ed,ok[100005]={0},vis[100005]={0},dis[100005]={0};
inline void Add(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
inline void Nadd(int x,int y)
{Edge[++cnt0].to=y,Edge[cnt0].nx=h0[x],h0[x]=cnt0;}
void BFS()
{
	vis[ed]=1;
	Q.push(ed);
	ok[ed]=1;
	while(!Q.empty())
	{
		int fr=Q.front();
		Q.pop();
		for(int i=h0[fr];i;i=Edge[i].nx)
		{
			int to=Edge[i].to;
			if(vis[to]) continue;
			Q.push(to);
			vis[to]=1;
			ok[to]=1;
		}
	}
}
void SPFA()
{
	Q.push(st);
	vis[st]=1;
	dis[st]=0;
	while(!Q.empty())
	{
		int fr=Q.front();
		vis[fr]=0;
		Q.pop();
		for(int i=h[fr];i;i=edge[i].nx)
		{
			int to=edge[i].to;
			int fl=0;
			for(int j=h[to];j;j=edge[j].nx)
			{
				int too=edge[j].to;
				if(ok[too]==0) {fl=1;break;}
			}
			if(fl) continue;
			if(dis[to]>dis[fr]+1)
			{
				dis[to]=dis[fr]+1;
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
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		Add(x,y);
		Nadd(y,x);
	}
	scanf("%d%d",&st,&ed);
	BFS();
	while(!Q.empty()) Q.pop();
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	SPFA();
	(dis[ed]==0x3f3f3f3f)?puts("-1"):printf("%d",dis[ed]);
	return 0;
}