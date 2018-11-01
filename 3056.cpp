#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int fr,to,val;}w[100005];
struct nodee{int to,nx,val;}edge[200005];
int dep[10005]={0},n,m,h[200005]={0},cnt=0,Q,fa[10005]={0},val[10005][50],dad[10005]={0},prt[10005][50]={0},x1,x2;
inline bool cmp(const node &a,const node &b)
{return a.val<b.val;}
inline void Add(int x,int y,int z)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt,edge[cnt].val=z;}
inline int Getfa(int x)
{return x==fa[x]?x:fa[x]=Getfa(fa[x]);}
void DFS(int x,int fa)
{
	prt[x][0]=fa;
	dep[x]=dep[fa]+1;
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		if(to!=fa)
		{
			DFS(to,x);
			val[to][0]=edge[i].val;
		}
	}
}
void Pre()
{
	for(int j=1;j<=(int)log2(n);j++)
		for(int i=1;i<=n;i++)
		{
			prt[i][j]=prt[prt[i][j-1]][j-1];
			val[i][j]=max(val[i][j-1],val[prt[i][j-1]][j-1]);
		}
}
int LCA(int a,int b)
{
	int ans=0;
	if(dep[b]>dep[a]) swap(a,b);
	for(int i=log2(dep[a]);i>=0;i--)
		if(dep[a]-(1<<i)>=dep[b])
		{
			ans=max(ans,val[a][i]);
			a=prt[a][i];
		}
	if(a==b) return ans;
	for(int i=log2(dep[a]);i>=0;i--)
	{
		if(prt[a][i]&&prt[a][i]!=prt[b][i])
		{
			ans=max(ans,max(val[a][i],val[b][i]));
			a=prt[a][i];
			b=prt[b][i];
		}
	}
	return max(ans,max(val[a][0],val[b][0]));
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&w[i].fr,&w[i].to,&w[i].val);
	sort(w+1,w+m+1,cmp);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	int ccnt=0;
	for(int i=1;i<=m;i++)
	{
		int fa1=Getfa(w[i].fr);
		int fa2=Getfa(w[i].to);
		if(fa1!=fa2)
		{
			ccnt++;
			Add(w[i].fr,w[i].to,w[i].val);
			Add(w[i].to,w[i].fr,w[i].val);
			fa[fa1]=fa2;
			if(ccnt==n-1) break;
		}
	}
	DFS(1,0);
	Pre();
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d",&x1,&x2);
		printf("%d\n",LCA(x1,x2));
	}
	return 0;
}