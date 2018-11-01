#include<iostream>
const int INF=0x3f3f3f3f;
using namespace std;
int in[3005]={0},cost[3005]={0},minn[3005]={0},ans=0,h[3005]={0},cnt=0,sign=0,n,m,p,buy[3005]={0},low[3005]={0},dfn[3005]={0},stack[3005]={0},ins[3005]={0},bel[3005]={0},top=0,scc=0;
struct node{int nx,to;}edge[8005];
void Addedge(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
void Init()// minn is alive 
{
	cin>>n>>p;
	for(int i=1;i<=n;i++)
		buy[i]=minn[i]=cost[i]=INF;
	int peo=0,mon=0;
	for(int i=1;i<=p;i++)
		cin>>peo>>mon,buy[peo]=mon;
	cin>>m;
	int a,b;
	for(int i=1;i<=m;i++)
		cin>>a>>b,Addedge(a,b);
}
void Tarjan(int x)
{
	dfn[x]=low[x]=++sign;
	stack[++top]=x;
	ins[x]=1;
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		if(!dfn[to])
		{
			Tarjan(to);
			low[x]=min(low[x],low[to]);
		}
		else if(ins[to]) low[x]=min(low[x],dfn[to]);
	}
	if(low[x]==dfn[x])
	{
		scc++;
		int hhh=0;
		do {
			hhh=stack[top--];
			minn[scc]=min(hhh,minn[scc]);
			cost[scc]=min(cost[scc],buy[hhh]);
			ins[hhh]=0;
			bel[hhh]=scc;
		}
		while(hhh!=x);
	}
	
}
void Solve()
{	
	int hehe=0;
	for(int i=1;i<=n;i++)
		if(!dfn[i])Tarjan(i);
	for(int i=1;i<=n;i++)
		for(int j=h[i];j;j=edge[j].nx)
			if(bel[i]!=bel[edge[j].to])in[bel[edge[j].to]]++;	
	ans=0;
	for(int i=1;i<=scc;i++)
		if(!in[i])
		{
			if(cost[i]==INF){hehe=1;break;}
			else ans+=cost[i];	
		}
	if(!hehe){cout<<"YES\n"<<ans<<endl;return;}
	ans=INF;
	for(int i=1;i<=scc;i++)
		if(!in[i]&&cost[i]==INF&&minn[i]<ans)ans=minn[i];
	cout<<"NO\n"<<ans<<endl;
}
int main(){
	Init();
	Solve();
	return 0;
}
/*
3						
2						
1 10
2 100
2
1 3
2 3

4						
2						
1 100
4 200
2
1 2
3 4
*/