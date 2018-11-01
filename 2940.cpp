#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
struct node{ll val,pos;}Q[100005];
ll n,k,dp[100005][5]={0},sum[100005]={0},L=1,R=1;
ll lqxio (ll x,ll y)
{return x>y?x:y;}
int main()
{
	scanf("%lld%lld",&n,&k);
	for(ll i=1,foo;i<=n;i++)
	{
		scanf("%lld",&foo);
		sum[i]=sum[i-1]+foo;
	}
	for(ll i=1;i<=n;i++)
	{
		dp[i][0]=lqxio(dp[i-1][0],dp[i-1][1]);
		while(L<=R&&Q[R].val<=dp[i][0]-sum[i]) R--;
		Q[++R].val=dp[i][0]-sum[i],Q[R].pos=i;
		while(L<=R&&Q[L].pos<i-k) L++;
		dp[i][1]=sum[i]+Q[L].val;
	}
	printf("%lld",lqxio(dp[n][0],dp[n][1]));
	return 0;
}
