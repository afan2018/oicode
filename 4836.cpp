#include<iostream>
#include<cstdio>
using namespace std;
const int MOD (1000000007);
int n,k,l,dp[25][1050000]={0},lim,ans=0;
int main()
{
	scanf("%d%d%d",&n,&k,&l);
	lim=(1<<k)-1;
	for(int i=1;i<=min(l,k);i++) dp[1][1<<(i-1)]=1;
	if(l>=k) dp[1][0]=l-k+1;
	for(int i=1;i<n;i++)
	{
		dp[i][0]=max(dp[i][0],1);
		for(int j=0;j<=lim;j++)
			if(dp[i][j])
			{
				for(int kk=0;kk<=min(k,l);kk++)
				{
					int foo=((j<<kk)|j|(1<<(kk-1)))&lim;
					dp[i+1][foo]=(dp[i][j]+dp[i+1][foo])%MOD;
				}
				if(l>=k) dp[i+1][j]=(1ll*dp[i][j]*(l-k)%MOD+dp[i+1][j])%MOD;
			}
	}
	for(int i=0;i<=lim;i++)
		if(i&(1<<(k-1)))
			ans=(ans+dp[n][i])%MOD;
	printf("%d",ans);
	return 0;
}