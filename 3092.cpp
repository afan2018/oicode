#include<iostream>
#include<iomanip>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
struct node{int to,nx,val;}edge[40005];
int h[40005]={0},cnt=0,n,sa,sb,sc,disa[20005]={0},disb[20005]={0},disc[20005]={0},minn=INF,vis[20005]={0};
queue<int>q;
void Add(int a,int b,int c)
{edge[++cnt].to=b,edge[cnt].nx=h[a],h[a]=cnt,edge[cnt].val=c;}
void SPFA(int v0,int dis[])
{
	while(!q.empty()) q.pop();
	fill(vis+1,vis+n+1,0);
	fill(dis+1,dis+n+1,INF);
	dis[v0]=0;
	vis[v0]=1;
	q.push(v0);
	while(!q.empty())
	{
		int fr=q.front();
		q.pop();
		for(int i=h[fr];i;i=edge[i].nx)
		{
			int to=edge[i].to;
			if(dis[fr]+edge[i].val<=dis[to])
			{
				dis[to]=dis[fr]+edge[i].val;
				if(!vis[to]) q.push(to),vis[to]=1;
			}
		}
	}
}
int main()
{
	//freopen("escape.in","r",stdin);
	//freopen("escape.out","w",stdout);
	cin>>n>>sa>>sb>>sc;
	for(int i=1,a,b,c;i<n;i++)
	{
		cin>>a>>b>>c;
		Add(a,b,c);
		Add(b,a,c);
	}
	SPFA(sa,disa);
	SPFA(sb,disb);
	SPFA(sc,disc);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(disa[i]+disb[i]+disc[i]<minn)
		{
			minn=disa[i]+disb[i]+disc[i];
			ans=i;
		}
	}
	cout<<ans<<endl<<minn;
	return 0;
}