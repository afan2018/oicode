#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n;
ll Power(ll x,ll idx)
{
	ll foo;
	if(idx==0) return 1%1234567;
	if(idx==1) return x%1234567;
	if(idx&1) {foo=Power(x,idx/2);return ((foo*foo)%1234567*x)%1234567;}
	else {foo=Power(x,idx/2);return foo*foo%1234567;}
}
int main()
{
	scanf("%lld",&n);
	n-=1;
	printf("%lld",Power(2,n)%1234567);
	return 0;
}
