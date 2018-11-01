#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
struct Bigint
{
	ll g,dig[4005];
	Bigint(){memset(dig,0,sizeof(dig));}
}ans,maxx;
struct Chan{ll l,r;}ch[1005];
ll n;
inline bool cmp(const Chan &a,const Chan &b)
{return a.l*a.r<b.l*b.r;}
void Print(Bigint a)
{
	printf("%lld",a.dig[a.g]);
	for(ll i=a.g-1;i>=1;i--)
		printf("%04lld",a.dig[i]);
	return;
}
Bigint operator *(const Bigint &a,const ll b)
{
	Bigint c;
	memcpy(c.dig,a.dig,sizeof(a.dig));
	c.g=a.g;
	for(ll i=1;i<=a.g;i++)
		c.dig[i]=a.dig[i]*b;
	for(ll i=1;i<=c.g;i++)
	{
		c.dig[i+1]+=c.dig[i]/10000;
		c.dig[i]%=10000;
	}
	while(c.dig[c.g+1]>0)
	{
		c.dig[c.g+1]+=c.dig[c.g]/10000;
		c.dig[c.g]%=10000;
		c.g++;
	}
	return c;
}
Bigint operator /(const Bigint &a,const ll b)
{
	Bigint c;
	memcpy(c.dig,a.dig,sizeof(a.dig));
	c.g=a.g;
	ll hh=0;
	for(ll i=c.g;i>=1;i--)
	{
		hh=hh*10000+a.dig[i];
		c.dig[i]=hh/b;
		hh%=b;
	}
	while(c.dig[c.g]==0&&c.g>0) c.g--;
	return c;
}
bool operator >(const Bigint a,const Bigint b)
{
	if(a.g>b.g) return true;
	if(a.g<b.g) return false;
	for(ll i=a.g;i>=1;i--)
	{
		if(b.dig[i]>a.dig[i]) return false;
		if(b.dig[i]<a.dig[i]) return true;
	}
	return false;
}
int main()
{
	scanf("%lld%lld%lld",&n,&ch[0].l,&ch[0].r);
	for(ll i=1;i<=n;i++)
		scanf("%lld%lld",&ch[i].l,&ch[i].r);
	sort(ch+1,ch+n+1,cmp);
	maxx.g=1;
	maxx.dig[1]=0;
	Bigint ans;
	ans.g=1;
	ans.dig[1]=1;
	for(ll i=1;i<=n;i++)
	{
		Bigint foo;
		ans=ans*ch[i-1].l;
		foo=ans/ch[i].r;
		if(foo>maxx) maxx=foo;
	}
	Print(maxx);
	return 0;
}