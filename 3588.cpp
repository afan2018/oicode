#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
struct node{int to,nx;}edge[10000];
int h[10000]={0},n,cnt=0,Q,prt[905][10],fa[905]={0},dep[905]={0},ans[905]={0};
inline void Add(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
void DFS(int x,int depth)
{
	dep[x]=depth;
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		DFS(to,depth+1);
	}
}
void ST()
{
	for(int i=1;i<=n;i++)
		prt[i][0]=fa[i];
	for(int j=1;j<=int(log2(n));j++)
		for(int i=1;i<=n;i++)
			if(prt[i][j-1]!=-1)
				prt[i][j]=prt[prt[i][j-1]][j-1];
}
void LCA(int a,int b)
{
	if(dep[b]>dep[a]) swap(a,b);//a is deeper
	int lim=log2(dep[a]);
	for(int i=lim;i>=0;i--)
		if(dep[a]-(1<<i)>=dep[b])
			a=prt[a][i];
	if(a==b) {ans[b]++;return;}
	lim=log2(dep[a]);
	for(int i=lim;i>=0;i--)
		if(prt[a][i]!=-1&&prt[a][i]!=prt[b][i])
		{
			a=prt[a][i];
			b=prt[b][i];
		}
	ans[prt[a][0]]++;
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(ans,0,sizeof(ans));
		memset(fa,0,sizeof(fa));
		memset(prt,-1,sizeof(prt));
		memset(h,0,sizeof(h));
		memset(dep,0,sizeof(dep));
		cnt=0;
		for(int i=1,id,num;i<=n;i++)
		{
			scanf("%d:(%d)",&id,&num);
			for(int j=1,x;j<=num;j++)
			{
				scanf("%d",&x);
				Add(id,x);
				fa[x]=id;
			}
		}
		int root=1;
		while(fa[root]) root=fa[root];
		DFS(root,1);
		ST();
		scanf("%d",&Q);
		while(Q--)
		{
			int x1,x2;
			scanf("\n(%d,%d)",&x1,&x2);
			LCA(x1,x2);
		}
		for(int i=1;i<=n;i++)
		if(ans[i]) printf("%d:%d\n",i,ans[i]);
	}	
	return 0;
}