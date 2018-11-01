#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
struct node{int ls,rs,val;}tree[305];
int n,m,f[305][305]={0},sbr[305]={0},note[305][305]={0},ans=0;
using namespace std;
void Init()
{
	cin>>n>>m;
	for(int i=1,x,y;i<=n;i++)
	{
		cin>>x>>y;
		tree[i].val=y;
		if(!sbr[x]) tree[x].ls=i;
		else tree[sbr[x]].rs=i;
		sbr[x]=i;
	}
}
int DFS(int x,int y)
{
	if(!x) return 0;
	if(f[x][y]) return f[x][y];
	f[x][y]=DFS(tree[x].rs,y);
	for(int i=1;i<=y;i++)
	{
		int tmp=DFS(tree[x].ls,i-1)+DFS(tree[x].rs,y-i);
		tmp+=tree[x].val;
		f[x][y]=max(f[x][y],tmp);
	}
	return f[x][y];
}
int main()
{
	Init();
	DFS(tree[0].ls,m);
	cout<<f[tree[0].ls][m];
	return 0;
}