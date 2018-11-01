#include<iostream>
#include<iomanip>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
struct node{int nx,to,val;}edge[100005];
struct nodee{int nx,to,val;}trans[100005];
int h[100005]={0},nh[100005]={0},cnt1=0,cnt2=0,n,m,dis[1005]={0},tdis[1005]={0},vis[1005]={0};
queue<int>q;
void Add(int x,int y,int z)
{edge[++cnt1].to=y,edge[cnt1].nx=h[x],h[x]=cnt1,edge[cnt1].val=z;}
void TAdd(int x,int y,int z)
{trans[++cnt2].to=y,trans[cnt2].nx=nh[x],nh[x]=cnt2,trans[cnt2].val=z;}
void FSPFA()
{
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	memset(dis,0x7f,sizeof(dis));
	vis[1]=1;
	dis[1]=0;
	q.push(1);
	
	while(!q.empty())
	{
		int fr=q.front();
		q.pop();
		vis[fr]=0;
		for(int i=h[fr];i;i=edge[i].nx)
		{
			int to=edge[i].to;
			if(dis[fr]+edge[i].val<dis[to])
			{
				dis[to]=dis[fr]+edge[i].val;
				if(!vis[to])
				{
					q.push(to);
					vis[to]=1;
				}
			}
		}
	}
}
void TSPFA()
{
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	memset(tdis,0x7f,sizeof(tdis));
	vis[1]=1;
	tdis[1]=0;
	q.push(1);
	while(!q.empty())
	{
		int fr=q.front();
		q.pop();
		vis[fr]=0;
		for(int i=nh[fr];i;i=trans[i].nx)
		{
			int to=trans[i].to;
			if(tdis[fr]+trans[i].val<tdis[to])
			{
				tdis[to]=tdis[fr]+trans[i].val;
				if(!vis[to])
				{
					q.push(to);
					vis[to]=1;
				}
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		Add(x,y,z);
		TAdd(y,x,z);//trans-edge
	}
	FSPFA();//forward SPFA
	TSPFA();//trans SPFA
	int sum=0;
	for(int i=2;i<=n;i++)
		sum+=dis[i]+tdis[i];
	cout<<sum;
	return 0;
}