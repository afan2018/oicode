#include<iostream>
using namespace std;
int top=0,prt[2505]={0},h[2505]={0},cnt=0,sign=0,bcc=0,low[2505]={0},dfn[2505]={0},stack[2505]={0},n,m,bel[2505]={0},out[2505]={0};
struct node{int nx,to;}edge[40005];
void Addedge(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
void Init()
{
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=m;i++)
		cin>>a>>b,Addedge(a,b),Addedge(b,a);
}
void Tarjan(int x)
{
	dfn[x]=low[x]=++sign;
	stack[++top]=x;
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		if(prt[x]!=to)
		{
			if(!dfn[to])
			{
				prt[to]=x;
				Tarjan(to);
				low[x]=min(low[x],low[to]);
			}
			else low[x]=min(low[x],dfn[to]);
		}
	}
	if(low[x]==dfn[x])
	{
		bcc++;
		int hhh=0;
		do hhh=stack[top--],bel[hhh]=bcc;
		while(hhh!=x);
	}
}
void Solve()
{
	for(int i=1;i<=n;i++)
		for(int j=h[i];j;j=edge[j].nx)
		{
			int to=edge[j].to;
			if(bel[to]!=bel[i])out[bel[i]]++;
		}
	int ans=0;
	for(int i=1;i<=bcc;i++)
		if(out[i]==1)ans++;
	cout<<(ans+1)/2<<endl;
}
int main(){
	Init();
	Tarjan(1);
	Solve();
	return 0;
}
/*
4 3
1 2
2 3
2 4
*/