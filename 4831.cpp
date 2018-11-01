#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int to,nx;}edge[80005];
int rt,n,m,h[80005],cnt=0,Find[40005]={0},comp[40005]={0},sign=0;
void Add(int a,int b)
{edge[++cnt].to=b,edge[cnt].nx=h[a],h[a]=cnt;}
void DFS(int x,int fa)
{
	Find[x]=++sign;
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		if(to!=fa)
			DFS(to,x);
	}
	comp[x]=++sign;
}
int main()
{
//	freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1,x,y;i<=n;i++)
	{
		cin>>x>>y;
		if(y==-1) rt=x;
		else Add(x,y),Add(y,x);
	}
	DFS(rt,-1);
	cin>>m;
	for(int i=1,x,y;i<=m;i++)
	{
		cin>>x>>y;
		if(Find[x]<=Find[y]&&comp[x]>=comp[y]) cout<<1<<endl;
		else if(Find[x]>=Find[y]&&comp[x]<=comp[y]) cout<<2<<endl;
		else cout<<0<<endl;
	}
	return 0;
}