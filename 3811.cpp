#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll MOD=1000000007ll;
int Prime[1000005],Comp[1000005]={0};
ll n,ans=1;
void Euler()
{
	for(int i=2;i<=n;i++)
	{
		if(!Comp[i]) Prime[++Prime[0]]=i;
		for(int j=1;j<=Prime[0]&&Prime[j]*i<=n;j++)
		{
			Comp[i*Prime[j]]=1;
			if(i%Prime[j]==0) break;
		}
	}
}
int main()
{
	scanf("%lld",&n);
	Euler();
	for(int i=1;i<=Prime[0];i++)
	{
		ll tot=0,num=Prime[i];
		while(num<=n)
		{
			tot+=(n/num)*2;
			num*=Prime[i];
		}
		ans=(ans*(tot+1))%MOD;
	}
	printf("%lld",ans);
	return 0;
}