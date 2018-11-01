#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll gx=1,r,k;
struct Bigint
{
	ll g,a[10005];
	Bigint(){memset(a,0,sizeof(a));}
}ans;
Bigint operator *(const Bigint &a,const ll &b)
{
	Bigint c;
	memcpy(c.a,a.a,sizeof(a.a));
	c.g=a.g;
	for(ll i=1;i<=a.g;i++)
		c.a[i]*=b;
	for(ll i=1;i<=c.g;i++)
	{
		c.a[i+1]+=c.a[i]/10;
		c.a[i]%=10;
	}
	while(c.a[c.g+1])
	{
		c.g++;
		c.a[c.g+1]+=c.a[c.g]/10;
		c.a[c.g]%=10;
	}
	return c;
}
Bigint operator /(const Bigint &a,const ll &b)
{
	Bigint c;
	memcpy(c.a,a.a,sizeof(a.a));
	c.g=a.g;
	ll d=0;
	for(ll i=a.g;i>=1;i--)
	{
		d=d*10+a.a[i];
		c.a[i]=d/b;
		d%=b;
	}
	while(c.g>0&&c.a[c.g]==0) c.g--;
	return c;
}
int main()
{
	scanf("%lld%lld",&k,&r);
	ll tmp=r;
	while(tmp)
	{
		if(tmp&1) gx=(gx*r)%1000;
		r=(r*r)%1000;
		tmp/=2;
	}
	ans.g=1;
	ans.a[1]=1;
	for(ll i=1;i<=k-1;i++)
	{
		ans=ans*(gx-k+i);
		ans=ans/i;
	}
	for(ll i=ans.g;i>=1;i--)
		printf("%d",ans.a[i]);
	return 0;
}