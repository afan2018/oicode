#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
queue<int>Q;
struct node{int to,nx,val;}edge[6005];
int h[1005]={0},cnt=0,n,m,dis[1005]={0},vis[1005]={0},bj[1005]={0};
void Add(int x,int y,int z)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt,edge[cnt].val=z;}
bool SPFA()
{
	Q.push(0);
	vis[0]=1;
	dis[0]=0;
	while(!Q.empty())
	{
		int fr=Q.front();
		vis[fr]=0;
		Q.pop();
		for(int i=h[fr];i;i=edge[i].nx)
		{
			int to=edge[i].to;
			if(dis[to]>edge[i].val+dis[fr])
			{
				dis[to]=edge[i].val+dis[fr];
				if(++bj[to]==n) return false;
				if(!vis[to])
				{
					vis[to]=1;
					Q.push(to);
				}
			}
		}
	}
	int minn=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		if(dis[i]==0x3f3f3f3f) return false;
		minn=min(minn,dis[i]);
	}
	if(minn<0)
		for(int i=1;i<=n;i++) dis[i]-=minn;
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		Add(y,x,z);
	}
	for(int i=1;i<=n;i++) Add(0,i,0);
	memset(dis,0x3f,sizeof(dis));
	if(SPFA())
		for(int i=1;i<=n;i++)
			printf("%d\n",dis[i]);
	else puts("NO SOLUTION");
	return 0;
}
/*
5 5
1 2 -3
1 5 -1
2 5 -1
5 1 -5
4 1 4
*/