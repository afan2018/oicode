#include<iostream>
using namespace std;
typedef long long ll;
ll a[1000005]={0},b;
ll bs(ll op,ll ed,ll f)
{
	ll mid,ans=-1;
	while(op<=ed)
	{
		mid=(op+ed)/2;
		if(a[mid]==f) {ans=mid;ed=mid-1;}
		if(a[mid]<f) op=mid+1;
		else ed=mid-1;
	}
	return ans;
} 
int main()
{
	ll n,f;
	scanf("%lld%lld",&n,&b);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	for(ll i=1;i<=b;i++)
	{
		scanf("%lld",&f);
		printf("%lld\n",bs(1,n,f));
	}
	return 0;
}