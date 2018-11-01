#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll MOD (1000000000ll);
int maxh[3005]={0},minh[3005]={0},L[3005]={0},R[3005]={0},n;
ll ans[3005]={0},dp[3005][35]={0};
int main()
{
	dp[1][1]=dp[0][0]=1,ans[1]=1;
	minh[1]=1,minh[2]=2;
	for(int i=3;i<=30;i++) minh[i]=minh[i-1]+minh[i-2]+1;
	maxh[1]=1;
	for(int i=2;i<=30;i++) maxh[i]=maxh[i-1]*2+1;
	for(int i=1;minh[i]<=3000&&i<=30;i++)
		for(int j=minh[i];j<min(minh[i+1],3000+1);j++)
			R[j]=i;
	L[1]=1;
	for(int i=2;maxh[i-1]<=3000&&i<=30;i++)
		for(int j=maxh[i-1]+1;j<=min(maxh[i],3000);j++)
			L[j]=i;
	for(int i=2;i<=3000;i++)
	{
		for(int l=0;l<i;l++)
		{
			int r=i-1-l;
			for(int h=max(0,L[i]-2);h<=min(29,R[i]-1);h++)
			{
				if(h) dp[i][h+1]=(dp[i][h+1]+dp[l][h]*dp[r][h-1])%MOD;
				dp[i][h+1]=(dp[i][h+1]+dp[l][h]*dp[r][h])%MOD;
				dp[i][h+2]=(dp[i][h+2]+dp[l][h]*dp[r][h+1])%MOD;
			}
		}
		for(int j=1;j<=min(29,i);j++) ans[i]=(ans[i]+dp[i][j])%MOD;
		ans[i]%=MOD;
	}
	while(scanf("%d",&n),n) printf(n>=38?"%09lld\n":"%lld\n",ans[n]);
	return 0;
}
