#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,m,k,low[10005]={0},high[10005]={0},up[10005]={0},down[10005]={0},dp[10005][1005]={0},sum[10005]={0},ans=0x3f3f3f3f;;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",up+i,down+i);
		low[i]=0;
		high[i]=m+1;	
	}
	low[n]=0;
	high[n]=m+1;
	for(int i=1,x,y,z;i<=k;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		low[x]=y;
		high[x]=z;
		sum[x]++;
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++) dp[0][i]=0;
	for(int i=1;i<=n;i++)
	{
		sum[i+1]+=sum[i];
		for(int j=up[i-1];j<=m;j++) dp[i][j]=min(dp[i][j],min(dp[i-1][j-up[i-1]],dp[i][j-up[i-1]])+1);
		for(int j=m-up[i-1];j<=m;j++) dp[i][m]=min(dp[i][m],min(dp[i-1][j],dp[i][j])+1);
		for(int j=low[i]+1;j<high[i];j++)
			if(j+down[i-1]<=m) dp[i][j]=min(dp[i][j],dp[i-1][j+down[i-1]]);
		for(int j=0;j<=low[i];j++) dp[i][j]=0x3f3f3f3f;
		for(int j=high[i];j<=m;j++) dp[i][j]=0x3f3f3f3f;
	}
	for(int i=1;i<=m;i++)
		ans=min(dp[n][i],ans);
	if(ans<0x3f3f3f3f) printf("1\n%d",ans);
	else
	{
		for(int i=n-1;i>=0;i--)
			for(int j=low[i]+1;j<high[i];j++)
				if(dp[i][j]<0x3f3f3f3f)
				{
					printf("0\n%d",sum[i]);
					return 0;
				}
	}
	return 0;
}