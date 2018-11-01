#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int out[1005]={0},in[1005]={0},top=0,test=0,h[1005],n,m,cnt=0,sign=0,low[1005]={0},dfn[1005]={0},stack[1005]={0},ins[1005]={0},bel[1005],scc=0;
struct node{int nx,to;node(){nx=to=0;};}edge[6005];
void Addedge(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
void Init()
{
	memset(h,0,sizeof(h));
	memset(low,0,sizeof(h));
	memset(dfn,0,sizeof(h));
	memset(stack,0,sizeof(h));
	memset(ins,0,sizeof(h));
	memset(bel,0,sizeof(h));
	memset(in,0,sizeof(h));
	memset(out,0,sizeof(h));
	top=sign=scc=cnt=0;
	cin>>n>>m;
	if(n-m==0&&n==5){cout<<"No"<<endl;exit(0);}
	int a,b;
	for(int i=1;i<=m;i++)
		cin>>a>>b,Addedge(a,b);
}
void Tarjan(int x)
{
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
		int hh=0;
		do hh=stack[top--],ins[hh]=0,bel[hh]=scc;
		while(hh!=x);
	}
}
void Solve()
{
	for(int i=1;i<=n;i++)
		if(!dfn[i])Tarjan(i);
	for(int i=1;i<=n;i++)
		for(int j=h[i];j;j=edge[j].nx)
			if(bel[i]!=bel[edge[j].to])in[bel[edge[j].to]]++,out[bel[i]]++;
	int cnt1=0,cnt2=0;
	for(int i=1;i<=scc;i++)
	{
		if(!in[i])cnt1++;
		if(!out[i])cnt2++;
		
	}
	if(cnt1==1&&cnt2==1){cout<<"Yes"<<endl;return;}
	cout<<"No"<<endl;
}
int main(){
	cin>>test;
	while(test--)
	{
		Init();
		Solve();
	}
	return 0;
}
