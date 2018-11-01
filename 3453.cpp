#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
struct node{int to,nx,val;}edge[200005];
int n,m,a,k,h[200005]={0},cnt=0,dis[10005]={0},vis[10005]={0},seq[10005]={0},sum=0;
queue<int>Q;
inline void Add(int x,int y,int z)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt,edge[cnt].val=z;}
void SPFA(int v0)
{
	memset(vis,0,sizeof(vis));
	sum-=(dis[v0]>=k);
	//不清空队列 
	dis[v0]=0;
	vis[v0]=1;
	Q.push(v0);
	while(!Q.empty())
	{
		int fr=Q.front();
		Q.pop();
		vis[fr]=0;
		if(dis[fr]>=k) continue; 
		for(int i=h[fr];i;i=edge[i].nx)
		{
			int to=edge[i].to;
			if(dis[to]>dis[fr]+edge[i].val)
			{
				sum-=(dis[to]>=k);
				dis[to]=dis[fr]+edge[i].val;
				if(!vis[to])
				{
					vis[to]=1;
					Q.push((to));
				}
				sum+=(dis[to]>=k);
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&k);
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		Add(x,y,z);
		Add(y,x,z);
	}
	sum=n;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=a;i++)
	{
		scanf("%d",seq+i);
		SPFA(seq[i]);
		printf("%d\n",sum);
	}
	return 0;
}