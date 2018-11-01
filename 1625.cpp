#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int INF=0x7ffffff;
struct node{int nx,to;}edge[2005];
int n,m,dp[2005][2005]={0},in[2005]={0},h[2005]={0},cnt=0;
void Add(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
void TreeBP(int v,int fa)
{
	dp[v][1]=in[v];
	for(int i=2;i<=m;i++)
		dp[v][i]=INF;
	for(int i=h[v];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		if(to!=fa)
		{
			TreeBP(to,v);
			for(int j=m;j>1;j--)
				for(int k=1;k<j;k++)
					dp[v][j]=min(dp[v][j],dp[to][k]+dp[v][j-k]-2);
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1,x,y;i<n;i++)
	{
		cin>>x>>y;
		Add(x,y);
		Add(y,x);
		in[y]++;
		in[x]++;
	}
	TreeBP(1,0);
	int ans=INF;
	for(int i=1;i<=n;i++)
		ans=min(dp[i][m],ans);
	cout<<ans;
	return 0;
}