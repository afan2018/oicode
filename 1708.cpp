#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int nx,to;}edge[20005];
int h[20005]={0},n,cnt=0,dp[3][10005]={0};
void Add(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
int TreeDP(int v,int fa,int flag)
{
	if(dp[flag][v]) return dp[flag][v];
	if(flag==0)
	{
		dp[flag][v]=1;
		for(int i=h[v];i;i=edge[i].nx)
		{
			int to=edge[i].to;
			if(to!=fa)
				dp[flag][v]+=min(TreeDP(to,v,0),min(TreeDP(to,v,2),TreeDP(to,v,1)));
		}
	}
	if(flag==1)
	{
		dp[flag][v]=0x7fffffff;
		int temp=TreeDP(v,fa,2);
		for(int i=h[v];i;i=edge[i].nx)
		{
			int to=edge[i].to;
			if(to!=fa)
				dp[flag][v]=min(dp[flag][v],temp-min(TreeDP(to,v,1),TreeDP(to,v,0))+TreeDP(to,v,0));
		}
	}
	if(flag==2)
	{
		for(int i=h[v];i;i=edge[i].nx)
		{
			int to=edge[i].to;
			if(to!=fa)
				dp[flag][v]+=min(TreeDP(to,v,1),TreeDP(to,v,0));
		}
	}
	return dp[flag][v];
}
int main()
{
	cin>>n;
	for(int i=1,x,y;i<n;i++)
	{
		cin>>x>>y;
		Add(x,y);
		Add(y,x);
	}
	cout<<min(TreeDP(1,0,1),TreeDP(1,0,0));
	return 0;
}

