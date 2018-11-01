#include<cstdio>
typedef long long ll;
struct node{ll a0,b0,c0;}Q[500005];
ll n,seq[50005]={0},cnt,ans[500005]={0};
int main()
{
	ll a,b,c;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&seq[i]);
	while(~scanf("%lld%lld%lld",&a,&b,&c))
	{
		Q[++cnt].a0=a;
		Q[cnt].b0=b;
		Q[cnt].c0=c;
	}
	ans[cnt-1]=-Q[cnt].a0;
	for(ll i=cnt-2;i>=1;i--)
	{
		ll foo=ans[i+1];
		ll bar=seq[ans[i+1]];
		ll l=foo*bar*bar+bar*bar+foo*bar+1;
		ll r=-(Q[i+1].a0*foo*bar*bar+Q[i+1].a0*bar*bar+Q[i+1].b0*foo*bar+foo*bar+Q[i+1].c0+foo);
		ans[i]=r/l;
	}
	for(ll i=1;i<cnt;i++) printf("%lld\n",ans[i]);
	return 0;
}
