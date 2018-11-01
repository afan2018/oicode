#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
queue<int>Q;
struct node{int to,nx,val;}edge[5005];
int h[1005]={0},cnt=0,n,dis[1005]={0},vis[1005]={0},st=0x3f3f3f3f,ed=0;
void Add(int x,int y,int z)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt,edge[cnt].val=z;}
void SPFA()
{
	Q.push(st);
	vis[st]=1;
	dis[st]=0;
	while(!Q.empty())
	{
		int fr=Q.front();
		vis[fr]=0;
		Q.pop();
		for(int i=h[fr];i;i=edge[i].nx)
		{
			int to=edge[i].to;
			if(dis[to]<edge[i].val+dis[fr])
			{
				dis[to]=edge[i].val+dis[fr];
				if(!vis[to])
				{
					vis[to]=1;
					Q.push(to);
				}
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y,z;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		st=min(st,x-1);
		ed=max(ed,y);
		Add(x-1,y,z);
	}
	for(int i=st;i<=ed;i++)
	{
		Add(i,i-1,-1);
		Add(i-1,i,0);
	}
	memset(dis,0xcf,sizeof(dis));
	SPFA();
	printf("%d",dis[ed]);
	return 0;
}