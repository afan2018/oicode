#include<iostream>
using namespace std;
const int INF=0x7f7f7f7f;
const int MAXN=2000005;
struct node{int to,nx,val;}edge[MAXN];
int h[MAXN]={0},cnt=0,n,m,stc[MAXN]={0},wei[MAXN]={0},stay[MAXN]={0},dis[MAXN]={0},vis[MAXN]={0},queue[MAXN]={0};
void Add(int a,int b,int c)
{edge[++cnt].to=b,edge[cnt].nx=h[a],h[a]=cnt,edge[cnt].val=c;}
void SPFA(int v0)
{
	int head=0,tail=0,lim=n*2;
	for(int i=1;i<=lim;i++) dis[i]=INF;
	dis[v0]=0;
	queue[++tail]=v0;
	vis[v0]=1;
	while(head<tail)
	{
		head++;
		int here=queue[head];
		vis[here]=0;
		for(int i=h[here];i;i=edge[i].nx)
		{
			int to=edge[i].to;
			if(dis[to]>dis[here]+edge[i].val)
			{
				dis[to]=dis[here]+edge[i].val;
				if(!vis[to])
				{
					queue[++tail]=to;
					vis[to]=1;
				}
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>stc[i];
	for(int i=1;i<=n;i++) cin>>wei[i];
	for(int i=1;i<=n;i++)
	{
		cin>>stay[i];
		Add(2*i,2*i-1,0);//even->white  odd->black
		Add(2*i-1,2*i,stay[i]);
	}
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		if(stc[x]==stc[y])
		{
			Add(2*x,2*y-1,z);
			Add(2*x-1,2*y,z);
		}
		else
		{
			int del=abs(wei[x]-wei[y]);
			Add(2*x,2*y,max(z-del,0));//while->black
			Add(2*x-1,2*y-1,z+del);//black->white
		}
	}
	if(stc[1]==0) SPFA(2);//(1*2)->start with white
	else SPFA(1);//(1*2-1)->start with black
	cout<<min(dis[2*n],dis[2*n-1])<<endl;
	return 0;
}
