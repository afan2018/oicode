#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int INF=0x7f7f7f7f;
class node{public: int nx,to,val;}edge[20005];
int minn=INF,n,m,cnt=0,map[1005][1005]={0},h[1005]={0},vis[1005]={0},dis[1005]={0};
queue<int>q;
void Add(int x,int y,int z)
{edge[++cnt].to=y,edge[cnt].nx=h[x],edge[cnt].val=z,h[x]=cnt;}
void SPFA(int v0)
{
	int h0[1005]={0},cnt0=cnt,fr,to;
	node edge0[20005];
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	memset(dis,INF,sizeof(dis));
	memcpy(h0,h,sizeof(h));
	memcpy(edge0,edge,sizeof(edge));
	dis[v0]=0;
	vis[v0]=1;
	for(int i=1;i<=n;i++)
		if(map[i][v0]) Add(i,n+1,map[i][v0]);
	q.push(v0);
	while(!q.empty())
	{
		fr=q.front();
		q.pop();
		for(int i=h[fr];i;i=edge[i].nx)
		{
			to=edge[i].to;
			if(dis[fr]+edge[i].val<=dis[to]) 
			{
				dis[to]=dis[fr]+edge[i].val;
				if(!vis[to]) q.push(to),vis[to]=1;
			}
		}
		vis[fr]=0;
	}
	cnt=cnt0;
	memcpy(h,h0,sizeof(h));
	memcpy(edge,edge0,sizeof(edge));
	minn=min(minn,dis[n+1]);
}
int main()
{
	cin>>n>>m;
	for(int i=1,a,b,c;i<=m;i++)
	{
		cin>>a>>b>>c;
		Add(a,b,c);
		map[a][b]=c;
	}
	for(int i=1;i<=n;i++)
		SPFA(i);
	cout<<minn;
	return 0;
}

