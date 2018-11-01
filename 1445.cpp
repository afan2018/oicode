#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int to,nx;}edge[12005];
int h[6005]={0},cnt=0,rt=1,n,hp[6005]={0},fa[6005]={0},inv[6005]={0},ninv[6005];
void Addedge(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
void Init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>hp[i];
	while(1)
	{
		int x,y;
		cin>>x>>y;
		if(x==y&&x==0) break;
		Addedge(y,x);
		fa[x]=y;
	}
	while(fa[rt]) rt=fa[rt];
}
void DFS(int x)
{
	if(!h[x])
	{
		inv[x]=hp[x];
		ninv[x]=0;
		return;
	}
	inv[x]=hp[x];
	ninv[x]=0;
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		DFS(to);
		inv[x]+=ninv[to];
		ninv[x]+=max(inv[to],ninv[to]);
	}
}
int main()
{
	Init();
	DFS(rt);
	cout<<max(inv[rt],ninv[rt]);
	return false;
}