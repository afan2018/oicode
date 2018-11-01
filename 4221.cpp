#include<iostream>
#include<iomanip>
#include<cstring>
#include<map>
#include<cstdio>
using namespace std;
typedef long long ll;
map<ll,ll>Map;
const ll MOD=1000000009;
ll dp[1000005]={0},n,seq[1000005]={0},sum[1000005]={0},c[1000007]={0};
int Lowbit(int x)
{return x&(-x);}
void Add(ll pos,ll x)
{
	x%=MOD;
	for(int i=pos;i<=n;i+=Lowbit(i))
		c[i]=(x+c[i])%MOD;
}
ll Ask(ll pos)
{
	int ret=0;
	for(int i=pos;i;i-=Lowbit(i))
		ret=(ret+c[i])%MOD;
	return ret;
}
int main()
{
	cin>>n;
	Map[0]=1;
	for(ll i=1;i<=n;i++)
	{
		cin>>seq[i];
		sum[i]=sum[i-1]+seq[i];
		Map[sum[i]]=1;
	}
	int j=1;
	for(map<ll,ll>::iterator it=Map.begin();it!=Map.end();it++,j++)
		it->second=j;
	for(int i=1;i<=n;i++)
		sum[i]=Map[sum[i]];
	Add(Map[0],1);
	for(int i=1;i<=n;i++)
	{
		dp[i]=Ask(sum[i])%MOD;
		Add(sum[i],dp[i]);
	}
	printf("%lld",dp[n]%MOD);
	return 0;
}