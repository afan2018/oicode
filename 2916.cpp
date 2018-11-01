#include<iostream>
using namespace std;
const int INF=0x7f7f7f7f/2;
int scc=0,tar=0,maxx=0,minn[5005]={0},bel[5005]={0},mval=0,size[5005]={0},top=0,n,m;
int cnt=0,sign=0,h[5005]={0},stack[5005]={0},ins[5005]={0},low[5005]={0},dfn[5005]={0};
struct node{int nx,to;}edge[200005];
void Addedge(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
void Init()
{
	cin>>n>>m;
	int a,b,c;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		Addedge(a,b);
		if(c==2) Addedge(b,a);
	}
}
void Tarjan(int x)
{
	int too=0;
	low[x]=dfn[x]=++sign;
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
	if(dfn[x]==low[x])
	{
		scc++;
		minn[scc]=INF;
		do {
			too=stack[top--];
			size[scc]++;
			minn[scc]=min(minn[scc],too);
			ins[too]=0;
			bel[too]=scc;
		}	
		while(too!=x);
	}
}
void Solve()
{
	for(int i=1;i<=n;i++)
		if(!dfn[i])Tarjan(i);
	for(int i=1;i<=scc;i++)
	{
		if(size[i]==maxx&&minn[i]<mval)tar=i,mval=minn[i];
		if(size[i]>maxx)tar=i,maxx=size[i],mval=minn[i];
	}
	cout<<maxx<<endl;
	for(int i=1;i<=n;i++)
		if(bel[i]==tar)cout<<i<<' ';
	cout<<endl;
}
int main(){
	Init();
	Solve();
	return 0;
}
/*
5 5
1 2 1
1 3 2
2 4 2
5 1 2
3 5 1
*/