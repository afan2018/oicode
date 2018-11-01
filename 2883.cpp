#include<iostream>
#include<queue>
using namespace std;
const int INF=1<<30;
struct _node {int next,to,val;}edge[20005];
int cnt,n,m,a,b,vvv,h[505],dis[505],sta,tar,vis[505]={0},path[505]={0};
struct node {
	int num,dis;
	bool operator <(node const &T) const
	{return (dis>T.dis||T.dis==dis&&num>T.num);}
};
priority_queue <node> q;
void AddEdge(int x,int y,int z)
{edge[++cnt].to=y,edge[cnt].val=z,edge[cnt].next=h[x],h[x]=cnt;}
void Init()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>vvv;
		AddEdge(a,b,vvv);
	}
	cin>>sta>>tar;
}
void print(int x)
{
	if(path[x]==x)
	{
		cout<<x<<' ';
		return;
	}
	else print(path[x]);
	cout<<x<<" ";
	return;
}
void Dijkestra(int st,int ed)
{
	int k;
	for(int i=1;i<=n;i++)
		dis[i]=INF,vis[i]=0;
	node t;
	t.dis=0;
	t.num=st;
	dis[st]=0;
	path[st]=st;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		if(vis[t.num])
		{q.pop();continue;}
		int x=t.num;
		vis[x]=1;
		if(x==ed)
		{
			cout<<dis[ed]<<endl;
			print(ed);
			return;
		}
		for(int i=h[x];i;i=edge[i].next)
		{
			k=edge[i].to;
			if(!vis[k]&&dis[k]>dis[x]+edge[i].val)
			{
				dis[k]=dis[x]+edge[i].val;
				t.num=k;
				path[k]=x;
				t.dis=dis[k];
				q.push(t);
			}
		}
	}
}
int main(){
	Init();
	Dijkestra(sta,tar);
	return 0;
}
/*
5 7
1 2 10
1 4 30
1 5 100
2 3 50
3 5 10
4 3 20
4 5 60
1 5
*/