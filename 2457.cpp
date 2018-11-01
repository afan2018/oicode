#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,m,l,x,y,d;
void Exgcd(ll a,ll b,ll &d,ll &x,ll &y)
{
	if(b==0) {d=a,x=1,y=0;return;}
	Exgcd(b,a%b,d,x,y);
	int foo=x;
	x=y;
	y=foo-(a/b)*y;
}
ll Power(ll x,ll idx)
{
	ll foo;
	if(!idx) return 1;
	if(idx==1) return x;
	if(idx%2) {foo=Power(x,(idx-1)/2);return ((foo*foo)%(n+1)*x)%(n+1);}
	else {foo=Power(x,idx/2);return (foo*foo)%(n+1);}
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&l);
	ll bar=2;
	bar=Power(bar,m);
	Exgcd(bar,n+1,d,x,y);
	printf("%lld",((x*l/d)%((n+1)/d)+(n+1)/d)%((n+1)/d));
	return 0;
}