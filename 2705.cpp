#include<cstdio>
inline int max(const int &a,const int &b)
{return a>b?a:b;}
struct node{int to,nx;}edge[205];
int dp[105][205][2]={0},n,h[205]={0},cnt=0,m;
inline void Add(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
void DP(int x,int fa)
{
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		if(to==fa) continue;
		DP(to,x);
		for(int j=m;j>=0;j--)
			for(int k=j-1;k>=0;k--)
			{	
				dp[x][j][0]=max(dp[x][j][0],dp[x][k][1]+dp[to][j-k-1][0]);
				if(j>=k+2)
				{
					dp[x][j][1]=max(dp[x][j][1],dp[x][k][1]+dp[to][j-k-2][1]);
					dp[x][j][0]=max(dp[x][j][0],dp[x][k][0]+dp[to][j-k-2][1]);
				}
			}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&dp[i][0][1]);
		dp[i][0][0]=dp[i][0][1];
	}
	for(int i=1,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		Add(x,y);
		Add(y,x);
	}
	scanf("%d",&m);
	DP(1,0);
	printf("%d",dp[1][m][0]);
	return 0;
}