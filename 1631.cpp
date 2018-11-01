#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll b,p,k,ans=1;
int main()
{
	scanf("%lld%lld%lld",&b,&p,&k);
	while(p)
	{
		if(p&1) ans=(b*ans%k);
		b=(b*b)%k;
		p/=2;
	}
	printf("%lld",ans);
	return 0;
}
