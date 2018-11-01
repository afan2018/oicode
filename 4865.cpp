#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
ll f[1005][1005]={0},T,n,k;
int main()
{
	f[1][0]=1;
	f[1][1]=0;
	f[2][1]=1;
	f[2][0]=1;
	for(ll i=3;i<=1000;i++)
	{
		f[i][0]=1;
		for(ll j=1;j<i;j++)
			f[i][j]=(f[i-1][j]%MOD*(j+1))%MOD+(f[i-1][j-1]%MOD*(i-j))%MOD;
	}
	scanf("%lld",&T);
	for(ll i=1,n,k;i<=T;i++)
	{
		scanf("%lld%lld",&n,&k);
		cout<<f[n][k]%MOD<<'\n';
	}
	return 0;
}
