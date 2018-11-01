#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const ll Prime[]={1,2,3,5,7,11,13,17,19,23,29,31,37};
ll a,b,maxx=0,ans=0;
void antiPrime(ll dep,int x,ll cnt,ll last)
{
	if(dep==11)
	{
		if(cnt>maxx) maxx=cnt,ans=x;
		else if(cnt==maxx&&x<ans) ans=x;
		return;
	}
	ll fac=1;
	for(ll i=0;i<=last;i++)
	{
		antiPrime(dep+1,x*fac,cnt*(i+1),i);
		fac*=Prime[dep];
		if(x*fac>b) return;
	}
	//deep and dreamless slumber
}
int main()
{
	scanf("%lld%lld",&a,&b);
	if(a<=100000)
	{
		for(ll i=a;i<=b;i++)
		{
			ll cnt=0;
			for(ll j=1;j*j<=i;j++)
			{
				if(i%j==0)
				{
					cnt++;
					if(i/j!=j) cnt++;
				}
			}
			if(cnt>maxx) ans=i,maxx=cnt;
		}
		printf("%lld",ans);
		return 0;
	}
	antiPrime(0,1,1,20);
	printf("%lld",ans);
	return 0;
}