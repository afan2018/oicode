#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
const int Maxn=200005,Maxm=1000005,Maxl=1<<30;
struct edge{int to,nx;double vl;} w[Maxm];
int n,m,cnt=0;
double dis[Maxn];
int h[Maxn];//dis:最短路 ,h:邻接表指针
bool vis[Maxn]= {0}; //标记
struct node
{
	int no;double dis;
	bool operator <(node const& T) const
	{
		return (dis>T.dis||dis==T.dis&&no>T.no);//STL堆小于号是大根堆，改小根堆的话就就反定义
	}
};
struct node1{int x;int y;}sit[105];
priority_queue <node> pq;
void AddEdge(int x,int y,double z)//邻接加边
{w[++cnt].to=y;w[cnt].nx=h[x];w[cnt].vl=z;h[x]=cnt;}
double Formula(int x,int y)
{
	double q=double(sit[x].x-sit[y].x),p=double(sit[x].y-sit[y].y);
	return sqrt(q*q+p*p);
}
void Dijkstra(int st,int ed)
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
	while(!pq.empty())//栈非空
	{
		t=pq.top();
		if(vis[t.no])
		{
			pq.pop();    //因为一个点多次压堆中，已标记的点弹出是忽略。
			continue;
		}
		int x=t.no;
		vis[x]=1;//设标志已找到时x点的最短路
		if(x==ed)
		{
			cout<<fixed<<setprecision(2)<<dis[x];  //找到了终点
			return;
		}
		for(j=h[x];j;j=w[j].nx)
		{
			k=w[j].to;//找与x相连的k点
			if(!vis[k]&&dis[k]>dis[x]+w[j].vl)
			{
				dis[k]=dis[x]+w[j].vl;//可以优化k点
				t.no=k;
				t.dis=dis[k];
				pq.push(t);//对K压堆中
			}
		}
	}
}
int main()
{
	int x,y;
	double z;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>sit[i].x>>sit[i].y;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		z=Formula(x,y);
		AddEdge(x,y,z);
		AddEdge(y,x,z);
		//cout<<z<<' ';
	}
	cin>>x>>y;
	Dijkstra(x,y);
	return 0;
}