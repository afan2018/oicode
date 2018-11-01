#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
struct node{int to,nx;}edge[100005];
int h[100005]={0},n,m,cnt=0,val[50005]={0},f[50005][21]={0},dep[50005]={0},sum[50005]={0},maxx=0;
inline int Getint()
{
	int ret=0,fl=1;
	char ch=getchar();
	while(ch>'9'||ch<'0') {if(ch=='-') fl=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {ret=ret*10+(ch-'0');ch=getchar();}
	return ret*fl;
}
inline void Add(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
void DFS(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		if(to!=fa) DFS(to,x);
	}
}
void ST()
{
	for(int i=1;i<=log2(n);i++)
		for(int j=1;j<=n;j++)
			if(f[j][i-1]!=-1)
				f[j][i]=f[f[j][i-1]][i-1];
}
int LCA(int x,int y)
{
	if(dep[y]>dep[x]) swap(x,y);
	int lim=log2(dep[x]);
	for(int i=lim;i>=0;i--)
		if(dep[x]-(1<<i)>=dep[y])
			x=f[x][i];
	if(x==y) return y;
	for(int i=lim;i>=0;i--)
		if(f[x][i]!=-1&&f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
void Get(int x,int fa)
{
	sum[x]=val[x];
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		if(to!=fa)
		{
			Get(to,x);
			sum[x]+=sum[to];
		}
	}
	maxx=max(maxx,sum[x]);
}
int main()
{
	n=Getint();
	m=Getint();
	for(int i=1,x,y;i<n;i++)
	{
		x=Getint();
		y=Getint();
		Add(x,y);
		Add(y,x);
	}
	memset(f,-1,sizeof(f));
	DFS(1,0);
	ST();
	for(int i=1,x,y;i<=m;i++)
	{
		x=Getint();
		y=Getint();
		val[x]++;
		val[y]++;
		int lca=LCA(x,y);
		val[lca]--;
		if(f[lca][0]!=-1) val[f[lca][0]]--;
	}
	Get(1,0);
	printf("%d",maxx);
	return 0;
}