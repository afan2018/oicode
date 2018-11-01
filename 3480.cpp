#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,seq[2005]={0},dp[2005][2005],s[2005]={0},ans=0x7f7f7f7f,f[2005][2005]={0};
inline bool cmp(const ll &a,const ll &b)
{return a>b;}
void DP()
{
	for(ll i=1;i<=n;i++)	
		for(ll j=1;j<=n;j++)
			f[i][j]=dp[i][j]=0x7f7f7f7f;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
		{
			dp[i][j]=f[i-1][j]+abs(seq[i]-s[j]);
			if(j==1) f[i][j]=dp[i][j];
			else f[i][j]=min(f[i][j-1],dp[i][j]);
		}
	for(ll i=1;i<=n;i++)
		ans=min(ans,dp[n][i]);
}
int main()
{
	scanf("%d",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%d",seq+i);
		s[i]=seq[i];
	}
	sort(s+1,s+n+1);
	DP();
	sort(s+1,s+n+1,cmp);
	DP();
	printf("%d",ans);
	return 0;
}