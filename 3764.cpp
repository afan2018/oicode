#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
struct node{int to,nx,val;}edge[1005];
int cnt=0,h[1005],n,dp[1005][105]={0},req[1005]={0},ans=0;
inline void Add(int x,int y,int z)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt,edge[cnt].val=z;}
void TreeDP(int x,int flow)
{
	for(int i=req[x];i<=flow;i++) dp[x][i]=1;
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		TreeDP(to,min(flow,edge[i].val));
		for(int j=flow;j>=0;j--)
			for(int k=0;k<=min(edge[i].val,j);k++)
				dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[to][k]);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,z;i<=n;i++)
	{
		scanf("%d%d%d",&x,&req[i],&z);
		Add(x,i,z);
	}
	for(int i=h[0];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		TreeDP(to,edge[i].val);
		ans+=dp[to][edge[i].val];
	}
	printf("%d",ans);
	return 0;
}
