#include<cstdio>
typedef long long ll;
ll n,m,k,x,ans=1,foo=10;
int main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
	while(k)
	{
		if(k&1) ans=ans*(foo)%n;
		foo=(foo*foo)%n;
		k/=2;
	}
	printf("%lld",(x%n+m*ans%n)%n);
	return 0;
}