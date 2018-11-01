#include<iostream>
using namespace std;
struct node{int nx,to;}edge[1000005];
int h[1000005]={0},cnt=0,n,scc=0,dfn[100005]={0},low[100005]={0},bel[100005]={0},sign=0,ins[100005]={0},stack[100005]={0},top=0;
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
		else if(ins[x]) low[x]=min(low[x],dfn[to]);
	}
	if(low[x]==dfn[x])
	{
		scc++;
		int hh;
		do
		{
			hh=stack[top--];
			ins[hh]=0;
			bel[hh]=scc;
		}
		while(hh!=x);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)
	{
		while(1)
		{
			scanf("%d",&x);
			if(x==0) break;
			Add(i,x);
		}
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			Tarjan(i);
	printf("%d\n",scc);
	return 0;
}
