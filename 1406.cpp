#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
const int Maxn=200005,Maxm=1000005,Maxl=1<<30;
struct edge{int to,nx,vl;}w[Maxm];
int n,m,cnt=0,s=0,maxx=0;
int dis[Maxn],h[Maxn];//dis:最短路 ,h:邻接表指针
bool vis[Maxn]= {0}; //标记
struct node
{
	int dis,no;
	bool operator <(node const& T) const
	{
		return (dis>T.dis||dis==T.dis&&no>T.no);//STL堆小于号是大根堆，改小根堆的话就就反定义
	}
}; 
priority_queue <node> pq;
void addedge(int x,int y,int z)//邻接加边
{w[++cnt].to=y,w[cnt].nx=h[x],w[cnt].vl=z,h[x]=cnt;}
void prim(int st)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		dis[i]=Maxl;//初始化距离为最大
		vis[i]=0;//标志初始化
	}
	node t;
	t.dis=0;
	t.no=st;
    dis[st]=0;
	pq.push(t);//起点压堆中
	while(!pq.empty())//栈`非空
	{
		t=pq.top();
		if(vis[t.no])
		{
			pq.pop();    //因为一个点多次压堆中，已标记的点弹出是忽略。
			continue;
		}
		int x=t.no;
		vis[x]=1;
		s++;
		
	//	cout<<dis[x]<<"$$$"<<endl;
		if(dis[x]>maxx)maxx=dis[x]; 
		for(j=h[x];j;j=w[j].nx)
		{
			k=w[j].to;//找与x相连的k点
			if(!vis[k]&&dis[k]>w[j].vl)
			{
				dis[k]=w[j].vl;//可以优化k点
				t.no=k;
				t.dis=dis[k];
				pq.push(t);
			}
		}
	}
}
int main()
{
	int x,y,z;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		addedge(x,y,z);
		addedge(y,x,z);
	}
	prim(1);
	cout<<s-1<<' '<<maxx;
	return 0;
}