#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,Q,dp[55][55][55]={0};
double ans[55][55]={0};
int main()
{
	cin>>n>>m;
	memset(dp,0x3f,sizeof(dp));
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		dp[x][y][1]=min(dp[x][y][1],z);
	}
	for(int t=2;t<=n;t++)//bianshu
		for(int k=1;k<=n;k++)//zhongjiandian
			for(int i=1;i<=n;i++)//qidian
				for(int j=1;j<=n;j++)//zhongdian
					if(dp[i][k][t-1]!=INF&&dp[k][j][1]!=INF)
						dp[i][j][t]=min(dp[i][j][t],dp[i][k][t-1]+dp[k][j][1]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{	
			ans[i][j]=1e100;
			for(int t=1;t<=n;t++)
			if(dp[i][j][t]!=INF)
				ans[i][j]=min(ans[i][j],1.0*dp[i][j][t]/t);
		}
	cin>>Q;
	for(int i=1,x,y;i<=Q;i++)
	{
		cin>>x>>y;
		if(ans[x][y]>=1e100) cout<<"OMG!\n";
		else printf("%.3lf\n",ans[x][y]);
	}
	return 0;
}