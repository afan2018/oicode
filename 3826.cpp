#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node0{int fr,to,val;}w[50005];
struct node1{int nx,to,val;}edge[50005];
int Q,n,m,h[50005]={0},cnt=0,fa[50005]={0},val[100005][25]={{0},{0}},dep[10005]={0},prt[10005][15]={{0},{0}};
inline void Add(int x,int y,int z)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt,edge[cnt].val=z;}
inline bool cmp(const node0 &a,const node0 &b)
{return a.val>b.val;}
inline int Getfa(int x)
{return x==fa[x]?x:fa[x]=Getfa(fa[x]);}
void Kruskal()
{
	int cnt0=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int fa1=Getfa(w[i].fr);
		int fa2=Getfa(w[i].to);
		if(fa1!=fa2)
		{
			fa[fa1]=fa2;
			cnt0++;
			Add(w[i].fr,w[i].to,w[i].val);
			Add(w[i].to,w[i].fr,w[i].val);
			if(cnt0==n-1) break;
		}
	}
}
void DFS(int x,int fa)
{
	dep[x]=dep[fa]+1;
	prt[x][0]=fa;
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		if(to==fa) continue;
		DFS(to,x);
		val[to][0]=edge[i].val;
	}
}
void ST()
{
	for(int i=1;i<=log2(n);i++)
		for(int j=1;j<=n;j++)
			if(~prt[j][i-1])
			{
				prt[j][i]=prt[prt[j][i-1]][i-1];
				val[j][i]=min(val[j][i-1],val[prt[j][i-1]][i-1]);
			}
}
int LCA(int a,int b)
{
	int ans=0x3f3f3f3f;
	if(dep[b]>dep[a]) swap(a,b);
	int lim=log2(dep[a]);
	for(int i=lim;i>=0;i--)
		if(dep[a]-(1<<i)>=dep[b])
		{
			ans=min(ans,val[a][i]);
			a=prt[a][i];
		}
	if(a==b) return ans;
	for(int i=lim;i>=0;i--)
		if(prt[a][i]&&prt[a][i]!=prt[b][i])
		{
			ans=min(ans,min(val[a][i],val[b][i]));
			a=prt[a][i];
			b=prt[b][i];
		}
	return min(ans,min(val[a][0],val[b][0]));
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&w[i].fr,&w[i].to,&w[i].val);
	sort(w+1,w+m+1,cmp);
	Kruskal();
	memset(val,0x3f,sizeof(val));
	memset(prt,-1,sizeof(prt));
	for(int i=1;i<=n;i++)
		if(!dep[i]) DFS(i,0);
	ST();
	scanf("%d",&Q);
	while(Q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		(Getfa(x)!=Getfa(y))?puts("-1"):printf("%d\n",LCA(x,y));
	}
	return 0;
}