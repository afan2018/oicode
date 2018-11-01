#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node{int to,nx,val,sta;}edge[20005];
struct nodee
{
	int x,pos;
	nodee(int x,int pos):x(x),pos(pos){}
};
queue<nodee>Q;
int h[20005]={0},cnt=0,n,m,C[25]={0},st,vis[1005][20]={0},dis[1005][20]={0},sta=0,ans=0x3f3f3f3f;
void Add(int x,int y,int z,int p)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt,edge[cnt].val=z,edge[cnt].sta=p;}
void SPFA()
{
	dis[1][st]=0;
	vis[1][st]=1;
	Q.push(nodee(1,st));
	while(!Q.empty())
	{
		nodee fr=Q.front();
		int fp=fr.x;
		int fs=fr.pos;
		vis[fp][fs]=0;
		Q.pop();
		for(int i=h[fp];i;i=edge[i].nx)
		{
			int to=edge[i].to;
			if(dis[fp][fs]+edge[i].val+abs(fs-edge[i].sta)<dis[to][edge[i].sta])
			{
				dis[to][edge[i].sta]=dis[fp][fs]+edge[i].val+abs(fs-edge[i].sta);
				if(!vis[to][edge[i].sta])
				{
					vis[to][edge[i].sta]=1;
					Q.push(nodee(to,edge[i].sta));
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",C+i);
		if(C[i]==0) st=i;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(C[j]!=0&&i+C[j]>=1&&i+C[j]<=n) Add(i,i+C[j],abs(C[j])*2,j);
	memset(dis,0x3f,sizeof(dis));
	SPFA();
	for(int i=1;i<=m;i++) ans=min(ans,dis[n][i]);
	(ans==0x3f3f3f3f)?puts("-1"):printf("%d",ans);
	return 0;
}
