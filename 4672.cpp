#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll dig[25]={0},dp[25][25][25][2],n;
ll DFS(ll pos,ll two,ll one,bool is322,bool hi)
{
	if(!pos) return is322;
	if(!hi&&~dp[pos][two][one][is322]) return dp[pos][two][one][is322];
	ll lim=hi?dig[pos]:9,cnt=0;
	for(ll i=0;i<=lim;i++)
		cnt+=DFS(pos-1,one,i,is322||(two==3&&one==2&&i==2),hi&&(i==lim));
	if(!hi) dp[pos][two][one][is322]=cnt;
	return cnt;
}
ll Q(ll x)
{
	dig[0]=0;
	while(x)
	{
		dig[++dig[0]]=x%10;
		x/=10;
	}
	return DFS(dig[0],0,0,0,1);
}
void BS(ll x)
{
	
	ll l=1,r=1ll<<62;
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(Q(mid)>=n) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	while(cin>>n) BS(n);
	return 0;
}