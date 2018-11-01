#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll x,y,m,n,L,d,a,b;
void Exgcd(ll a,ll b,ll &d,ll &x,ll &y)
{
	if(b==0) {d=a,x=1,y=0;return;}
	Exgcd(b,a%b,d,x,y);
	ll foo=x;
	x=y;
	y=foo-(a/b)*y;
}
int main()
{
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L);
	if(n-m<0) swap(x,y),swap(m,n);
	Exgcd(n-m,L,d,a,b);
	if((x-y)%d||m==n) puts("Impossible");
	else printf("%lld",((a*(x-y)/d)%(L/d)+L/d)%(L/d));
	return 0;
}