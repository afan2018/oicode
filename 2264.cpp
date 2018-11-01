#include<iostream>
using namespace std;
typedef long long ll;
const ll MAX=2100000000ll;
ll n,tmp[100]={0},foo;
ll Come(ll x)
{
	int cnt=0;
	ll ret=0;
	while(x)
	{
		tmp[++cnt]=x%2;
		x/=2;
	}
	for(int i=cnt;i>=1;i--)
		ret=ret*10+tmp[i];
	return ret;
}
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=MAX;i++)
	{
		foo=Come(i);
		if(foo%n==0)
		{
			printf("%lld\n",foo/n);
			return 0;
		}
	}
	return 0;
}
