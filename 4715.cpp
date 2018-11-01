#include<cstdio>
typedef long long ll; 
int main()
{
	ll n,x=0,tp;
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld",&tp);
		x^=tp;
	}
	printf("%lld\n",x);
    return 0;
}