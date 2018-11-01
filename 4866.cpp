#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct node{int to,fr;}edge[800005];
struct NODE{int to,nx;}e[800005];
int vis[400005]={0},fl[800005]={0},n,m,fa[400005]={0},val[400005]={0},del[400005]={0},h[400005]={0},cnt=0,ha[400005]={0};
int Getfa(int x)
{return x==fa[x]?x:fa[x]=Getfa(fa[x]);}
void Add(int x,int y)
{e[++cnt].to=y,e[cnt].nx=h[x],h[x]=cnt;}
void DFS2(int x,int fa,int T)
{
	if(vis[x]) return;
	val[x]=T;
	vis[x]=1;
	for(int i=h[x];i;i=e[i].nx)
	{
		int to=e[i].to;
		if(to==fa) continue;
		DFS2(to,x,T);
	}
}
void DFS1(int x,int fa)
{
	if(ha[x]) return;
	ha[x]=1;
	for(int i=h[x];i;i=e[i].nx)
	{
		int to=e[i].to;
		if(to==fa) continue;
		DFS1(to,x);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&edge[2*i-1].to,&edge[2*i].to);
		edge[2*i-1].fr=edge[2*i].fr=i;
	}
	for(int i=1,x,bj;i<=m;i++)
	{
		scanf("%d%d",&x,&bj);
		if(bj==1) fl[2*x-1]=1,del[i]=2*x-1;
		else fl[2*x]=1,del[i]=2*x;
	}
	memset(val,0x3f,sizeof(val));
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=2*n;i++)
	{
		if(edge[i].to==-1||fl[i]) continue;
		int fa1=Getfa(edge[i].fr),fa2=Getfa(edge[i].to);
		if(fa1!=fa2) fa[fa1]=fa2;
		Add(edge[i].fr,edge[i].to);
		Add(edge[i].to,edge[i].fr);
	}
	DFS1(1,0);
	for(int i=1;i<=n;i++)
		if(ha[i]) vis[i]=1,val[i]=-1;
	for(int i=m;i>=1;i--)
	{
		int fa1=Getfa(edge[del[i]].fr),fa2=Getfa(edge[del[i]].to);
		if(fa1!=fa2) fa[fa1]=fa2;
		if(Getfa(edge[del[i]].fr)==Getfa(1)) DFS2(edge[del[i]].fr,0,i-1);
		if(Getfa(edge[del[i]].to)==Getfa(1)) DFS2(edge[del[i]].to,0,i-1);
		Add(edge[del[i]].fr,edge[del[i]].to);
		Add(edge[del[i]].to,edge[del[i]].fr);
	}
	for(int i=1;i<=n;i++)
	{
		if(val[i]==0x3f3f3f3f) val[i]=0;
		cout<<val[i]<<'\n';
	}
	return 0;
}
