#include<iostream>
using namespace std;
const int INF=0x7f7f7f7f/2;
int ans=0,out[10005]={0},scc=0,tar=0,maxx=0,minn[10005]={0},bel[10005]={0},mval=0,size[10005]={0},top=0,n,m;
int cnt=0,sign=0,h[10005]={0},stack[10005]={0},ins[10005]={0},low[10005]={0},dfn[10005]={0};
struct node{int fr,nx,to;}edge[50005];
void Addedge(int x,int y)
{edge[++cnt].to=y,edge[cnt].fr=x,edge[cnt].nx=h[x],h[x]=cnt;}
void Init()
{
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		Addedge(a,b);
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
	for(int i=1;i<=m;i++)
		if(bel[edge[i].fr]!=bel[edge[i].to]) 
			out[bel[edge[i].fr]]++;
	for(int i=1;i<=scc;i++)
		if(!out[i])ans++,tar=i;
	if(ans==1)
	{
		int anss=0;
		for(int i=1;i<=n;i++)
			if(bel[i]==tar)anss++;
		cout<<anss<<endl;
	}
	else cout<<0;
}
int main(){
	Init();
	Solve();
	return 0;
}
/*
3 3
1 2
2 1
2 3
*/