#include<iostream>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
struct node{int to,nx;}edge[20005];
int dp[10005][2]={0},n,m,Color[6005],h[20005]={0},cnt=0;
inline void Add(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
void DP(int x,int fa)
{
	if(x<=m) return;
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		if(to==fa) continue;
		DP(to,x);
		dp[x][1]+=min(dp[to][0],dp[to][1]-1);
		dp[x][0]+=min(dp[to][1],dp[to][0]-1);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",Color+i);
	for(int i=1,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		Add(x,y);
		Add(y,x);
	}
	for(int i=1;i<=m;i++)
	{
		dp[i][Color[i]]=1;
		dp[i][!Color[i]]=INF;
	}
	for(int i=m+1;i<=n;i++)
		dp[i][1]=dp[i][0]=1;
	DP(n,0);
	printf("%d",min(dp[n][1],dp[n][0]));
	return 0;
}
