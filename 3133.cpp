#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,S,sum[2000005]={0},ans=0x3f3f3f3f;
int main()
{
	scanf("%lld%lld",&n,&S);
	for(ll i=1,x;i<=n;i++)
	{
		scanf("%lld",&x);
		sum[i]=sum[i-1]+x;
	}
	ll L=0;
	for(ll i=1;i<=n;i++)
	{
		while(sum[i]-sum[L]>S) L++;
		if(L>0&&sum[i]-sum[L]<S) L--;
		if(sum[i]-sum[L]>=S) ans=min(ans,i-L);
	}
	printf("%lld",ans);
	return 0;
}
