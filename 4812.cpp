#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int to,nx;}edge[200005];
int n,m,h[100005]={0},ans=0,vis[100005]={0},ccnt[3]={0},cnt=0;
void Add(int a,int b)
{edge[++cnt].to=b,edge[cnt].nx=h[a],h[a]=cnt;}
bool DFS(int x,int col)//1->F 2->J
{
	if(vis[x]&&vis[x]!=col) return false;
	if(vis[x]) return true;
	vis[x]=col,ccnt[col]++;
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		if(!DFS(to,3-col)) return false;
	}
	return true;
}
int main()
{
	cin>>n>>m;
	for(int i=1,a,b;i<=m;i++)
	{
		cin>>a>>b;
		Add(a,b);
		Add(b,a);
	}
	bool flag=1;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			flag=DFS(i,1);
			if(!flag) {cout<<"-1";return 0;}
			else ans+=max(ccnt[1],ccnt[2]);
			ccnt[1]=ccnt[2]=0;
		}
	cout<<ans;
	return 0;
}
