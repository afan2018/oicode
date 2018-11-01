#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll hh[]={6,2,5,5,4,5,6,3,7,5};
ll dp[205][105],n,pow10[105]={0},dig[105]={0},ans=0;
ll num,hehe;
ll DFS(ll pos,ll sum,bool hi)
{
	if(pos==0) return sum==ans;
	if(!hi&&dp[pos][sum]!=-1) return dp[pos][sum];
	ll lim=(hi?dig[pos]:9);
	ll rett=0ll;
	for(ll i=0;i<=lim;i++)
		rett+=DFS(pos-1,sum+((pos<=n)?hh[i]:0),(i==lim)&&hi);
	return hi?rett:dp[pos][sum]=rett;
}
bool Check(ll x)
{
	memset(dp,-1,sizeof(dp));
	memset(dig,0,sizeof(dig));
	while(x)
	{
		dig[++dig[0]]=x%10;
		x/=10;
	}
	ll kk=DFS(max(dig[0],n),0,1);
	return kk>hehe;
}
ll Count()
{
	memset(dp,-1,sizeof(dp));
	ll tmp=num;
	while(tmp)
	{
		dig[++dig[0]]=tmp%10;
		tmp/=10;
	}
	for(ll i=1;i<=n;i++)
		ans+=hh[dig[i]];
	hehe=DFS(n,0,1);
	memset(dig,0,sizeof(dig));
	ll l=num+1,r=num+1+pow10[n],mid,ret=-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(Check(mid)) ret=mid,r=mid-1;
		else l=mid+1;
	}
	return ret-num;
}
int main()
{
	memset(dp,0,sizeof(dp));
	pow10[1]=10;
	for(ll i=2;i<=25;i++)
		pow10[i]=pow10[i-1]*10;
	scanf("%lld%lld",&n,&num);
	printf("%lld",Count());
	return 0;
}
