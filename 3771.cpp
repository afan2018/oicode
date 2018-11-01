#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
struct node{int to,nx,x;}edge[6005];
struct Node{int cnt,x;};
queue<int>Q;
queue<Node>q;
int map[305][305]={0},d[305]={0},h[3005]={0},cnt=0,n,m,e,p,L,K,vis[305]={0},bj[305]={0},g0[305][305]={0},g[305][305]={0},dis[35][305]={0},v[305][305]={0},ans=0x3f3f3f3f;
void Add(int x,int y,int z)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt,edge[cnt].x=z;}
void SPFA1()
{
	memset(d,0x3f,sizeof(d));
	Q.push(0);
	d[0]=0;
	vis[0]=1;
	while(!Q.empty())
	{
		int fr=Q.front();
		vis[fr]=0;
		Q.pop();
		for(int i=h[fr];i;i=edge[i].nx)
		{
			int to=edge[i].to;
			if(d[to]>d[fr]+edge[i].x)
			{
				d[to]=d[fr]+edge[i].x;
				if(!vis[to])
				{
					vis[to]=1;
					Q.push(to);
				}
			}
		}
	}
	for(int i=1;i<=n;i++) bj[i]=d[i]-d[i-1];
}
void Floyd()
{
	memset(g0,0x3f,sizeof(g0));
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			g0[i][j]=g[i][j]=map[i][j];
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(g0[i][k]!=0x3f3f3f3f&&g0[k][j]!=0x3f3f3f3f)
					g0[i][j]=min(g0[i][j],g0[i][k]+g0[k][j]);
	for(int k=1;k<=n;k++) 
	{
		if(bj[k]) continue;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(g[i][k]!=0x3f3f3f3f&&g[k][j]!=0x3f3f3f3f)
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	}
}
void SPFA2()
{
	memset(dis,0x3f,sizeof(dis));
	Node foo,bar;
	foo.cnt=0,foo.x=1;
	q.push(foo);
	v[0][1]=1;
	dis[0][1]=0;
	while(!q.empty())
	{
		foo=q.front();
		v[foo.cnt][foo.x]=0;
		q.pop();
		for(int i=1;i<=n;i++)
		{
			if(dis[foo.cnt][i]>dis[foo.cnt][foo.x]+g0[foo.x][i])
			{
				dis[foo.cnt][i]=dis[foo.cnt][foo.x]+g0[foo.x][i];
				if(!v[foo.cnt][i])
				{
					bar.cnt=foo.cnt;
					bar.x=i;
					v[bar.cnt][i]=1;
					q.push(bar);
				}
			}
		}
		if(foo.cnt>=K) continue;
		for(int i=1;i<=n;i++)
		{
			if(g[foo.x][i]<=L&&dis[foo.cnt+1][i]>dis[foo.cnt][foo.x])
			{
				dis[foo.cnt+1][i]=dis[foo.cnt][foo.x];
				if(!v[foo.cnt+1][i])
				{
					bar.cnt=foo.cnt+1;
					bar.x=i;
					v[bar.cnt][i]=1;
					q.push(bar);
				}
			}
		}
	}
	for(int i=0;i<=K;i++) ans=min(ans,dis[i][n]);
}
void Init()
{
	scanf("%d%d%d%d%d%d",&n,&m,&e,&p,&L,&K);
	memset(map,0x3f,sizeof(map));
	for(int i=1,x,y,z;i<=e;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		map[x][y]=map[y][x]=min(z,map[x][y]);
	}
	for(int i=1,x,y,z;i<=p;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		Add(y,x-1,-z);
	}
	for(int i=1;i<=n;i++)
	{
		Add(i-1,i,1);
		Add(i,i-1,0);
	}
	Add(0,n,m);
	Add(n,0,-m);
}
int main()
{
	Init();
	SPFA1();
	Floyd();
	SPFA2();
	printf("%d",ans);
	return 0;
}