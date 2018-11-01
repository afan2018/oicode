#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct node{int to,nx;}edge[400005];
struct nodee{int to,nx,num;}query[400005];
int ans,n,m,h[200005]={0},cnt=0,qcnt=0,fa[200005]={0},root,vis[200005]={0},mark[200005]={0},h0[200005]={0};
inline void Addedge(int a,int b)
{edge[++cnt].to=b,edge[cnt].nx=h[a],h[a]=cnt;}
inline void Addquery(int a,int b)
{query[++qcnt].to=b,query[qcnt].nx=h0[a],h0[a]=qcnt;}
inline int Getfa(int x)
{return x==fa[x]?x:fa[x]=Getfa(fa[x]);}
void Tarjan(int x)
{
	vis[x]=1;
	fa[x]=x;
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		if(!vis[to])
		{
			Tarjan(to);
			fa[to]=x;
		}
	}
	mark[x]=1;
	for(int i=h0[x];i;i=query[i].nx)
	{
		int to=query[i].to;
		if(mark[to]) ans=Getfa(to);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		Addedge(x,y);
		fa[y]=x;
	}
	root=1;
	while(fa[root]) root=fa[root];
       int x,y;
	scanf("%d%d",&x,&y);
	Addquery(x,y);
	Addquery(y,x);
	Tarjan(root);
	printf("%d\n",ans);
	return 0;
}
