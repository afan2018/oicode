#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,dp[205]={0},h[205]={0};
int main()
{
	cin>>n;
	memset(dp,0x3f,sizeof(dp));
	for(ll i=1;i<=n;i++)
		cin>>h[i];
	dp[1]=0;
	for(ll i=2;i<=n;i++)
	{
		if(h[i]==h[i-1]+1) dp[i]=dp[i-1]+1;
		for(ll k=1;k<i;k++)
			for(ll j=1;j<k;j++)
				if((1<<(k-j))+h[j]>=h[i])
					dp[i]=min(dp[i],dp[k]+k-j+1);
	}
	if(dp[n]>=0x3f3f3f3f) dp[n]=-1;
	cout<<dp[n]<<endl;
	return 0;
}
