#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
queue<int>q;
struct node{int to,nx,val,old;}edge[100005];
int n,m,T,cnt=0,h[100005]={0},dis[20005]={0},vis[20005]={0},L,R=0,mid,ans=-1;
inline void Add(int x,int y,int z,int p)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt,edge[cnt].val=z,edge[cnt].old=p;}
void SPFA(int lim)
{
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	q.push(1);
	vis[1]=1;
	dis[1]=0;
	while(!q.empty())
	{
		int fr=q.front();
		q.pop();
		vis[fr]=0;
		for(int i=h[fr];i;i=edge[i].nx)
		{
			if(edge[i].old<=lim) continue;
			int to=edge[i].to;
			if(dis[to]>dis[fr]+edge[i].val)
			{
				dis[to]=dis[fr]+edge[i].val;
				if(!vis[to])
				{
					vis[to]=1;
					q.push(to);
				}
			}
		}
	}
}
bool Check(int x)
{
	SPFA(x);
	if(dis[n]>=T) return true;
	return false;
}
int main()
{
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1,x,y,z,p;i<=m;i++)
	{
		scanf("%d%d%d%d",&x,&y,&z,&p);
		Add(x,y,z,p);
		R=max(R,p);
	}
	SPFA(0);
	if(dis[n]>=T) {printf("-1 %d",dis[n]);return 0;}
	while(L<=R)
	{
		mid=(L+R)/2;
		if(Check(mid)) ans=mid,R=mid-1;
		else L=mid+1;
	}
	printf("%d",ans);
	return 0;
}