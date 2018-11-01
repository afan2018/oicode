#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct node{int to,nx;}edge[200005];
int n,h[100005]={0},cnt=0,m,dep[100005]={0},son[100005]={0},prt[100005][20]={0},a,b,fl[100005]={0};
void Add(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
void DFS(int x,int fa)
{
	dep[x]=dep[fa]+1;
	prt[x][0]=fa;
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		if(to==fa) continue;
		son[x]++;
		DFS(to,x);
	}
	son[fa]+=son[x];
}
void ST()
{
	for(int i=1;i<=log2(n);i++)
		for(int j=1;j<=n;j++)
			if(prt[j][i-1]!=-1)
				prt[j][i]=prt[prt[j][i-1]][i-1];
}
int LCA(int a,int b)
{
	if(dep[a]<dep[b]) swap(a,b);
	int lim=log2(dep[a]);
	for(int i=lim;i>=0;i--)
		if(dep[a]-(1<<i)>=dep[b])
			a=prt[a][i];
	if(a==b) return b;
	for(int i=lim;i>=0;i--)
		if(prt[a][i]!=-1&&prt[a][i]!=prt[b][i])
			a=prt[a][i],b=prt[b][i];
	return prt[a][0];
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		Add(x,y);
		Add(y,x);
	}
	memset(prt,-1,sizeof(prt));
	DFS(1,0);
	ST();
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		if(a==b) {cout<<n<<'\n';continue;}
		int lca=LCA(a,b),len=0;
		if(dep[a]<dep[b]) swap(a,b);
		int ta=a,tb=b;
		fl[lca]=i;
		while(a!=lca)
		{
			fl[a]=i;
			a=prt[a][0];
			len++;
		}
		while(b!=lca)
		{
			fl[b]=i;
			b=prt[b][0];
			len++;
		}
		if(len&1) {puts("0");continue;}
		a=ta,b=tb;
		if(dep[a]==dep[b])
		{
			int ans=n;
			for(int j=h[lca];j;j=edge[j].nx)
			{
				int to=edge[j].to;
				if(fl[to]==i) ans-=son[to]+1;
			}
			cout<<ans<<'\n';
			continue;
		}
		int sum=len/2;
		while(a!=lca&&sum!=0) a=prt[a][0],sum--;
		int ans=son[a]+1;
		for(int j=h[a];j;j=edge[j].nx)
		{
			int to=edge[j].to;
			if(to!=prt[a][0]&&fl[to]==i) ans-=son[to]+1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
