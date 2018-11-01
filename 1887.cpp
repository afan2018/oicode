#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
queue<int>Q;
struct node{int to,nx,val;}edge[6005];
int n,A0,B0,L0,A1,B1,L1,dis[1005]={0},h[1005]={0},cnt=0,vis[1005]={0},bj[1005]={0};
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
				if(++bj[to]>=n) return false;
				if(!vis[to])
				{
					vis[to]=1;
					Q.push(to);
				}
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d%d%d%d%d%d%d",&n,&A0,&B0,&L0,&A1,&B1,&L1);
	for(int i=L0;i<=n;i++)
	{
		Add(i-L0,i,L0-A0);
		Add(i,i-L0,B0-L0);
	}
	for(int i=L1;i<=n;i++)
	{
		Add(i-L1,i,B1);
		Add(i,i-L1,-A1);
	}
	for(int i=1;i<=n;i++)
	{
		Add(i-1,i,1);
		Add(i,i-1,0);
	}
	memset(dis,0x3f,sizeof(dis));
	SPFA()?printf("%d",dis[n]):puts("-1");
	return 0;
}
