#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll; 
const ll Prime[]={1,2,3,5,7,11,13,17,19,23,29,31,37};
ll maxx=0,ans=0,n;
void antiPrime(ll dep,ll x,ll cnt,ll last)
{
	if(dep==12)
	{
		if(cnt>maxx) ans=x,maxx=cnt;
		else if(cnt==maxx&&x<ans) ans=x;
		return;
	}
	ll fac=1;
	for(ll i=0;i<=last;i++)
	{
		antiPrime(dep+1,x*fac,cnt*(i+1),i);
		fac*=Prime[dep];
		if(x*fac>n) return;
	}
}
int main()
{
	scanf("%lld",&n);
	antiPrime(0,1,1,20);
	printf("%lld",ans);
	return 0;
}
