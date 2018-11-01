#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
struct node{ll to,nx,val;}edge[2000005];
ll n,h[2000005]={0},cnt=0,dp[1000005]={0},val[1000005]={0},SUM=0,ans;
inline void Add(ll x,ll y,ll z)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt,edge[cnt].val=z;}
void TreeDP1(ll x,ll fa)
{
	for(ll i=h[x];i;i=edge[i].nx)
	{
		ll to=edge[i].to;
		if(to!=fa)
		{
			TreeDP1(to,x);
			val[x]+=val[to];
			dp[x]+=dp[to]+edge[i].val*val[to];
		}
	}
}
void TreeDP2(ll x,ll fa)
{
	for(ll i=h[x];i;i=edge[i].nx)
	{
		ll to=edge[i].to;
		if(to!=fa)
		{
			dp[to]=dp[x]+(SUM-val[to])*edge[i].val-edge[i].val*val[to];
			TreeDP2(to,x);
		}
	}
}
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",val+i);
		SUM+=val[i];
	}
	for(ll i=1,x,y,z;i<n;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		Add(x,y,z);
		Add(y,x,z);
	}
	TreeDP1(1,0);
	TreeDP2(1,0);
	ans=dp[1];
	for(ll i=1;i<=n;i++)
		ans=min(ans,dp[i]);
	printf("%lld",ans);
	return 0;
}