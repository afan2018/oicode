#include<cstdio>
typedef long long ll;
ll a,b,d,x,y;
void Exgcd(ll a,ll b,ll &d,ll &x,ll &y)
{
	if(b==0) {d=a,x=1,y=0;return;}
	Exgcd(b,a%b,d,x,y);
	int foo=x;
	x=y;
	y=foo-(a/b)*y;
}
int main()
{
	scanf("%lld%lld",&a,&b);
	Exgcd(a,b,d,x,y);
	printf("%lld\n",((x%(b/d)+(b/d))%(b/d)));
	return 0;
}
