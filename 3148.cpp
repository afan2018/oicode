#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
typedef long long ll;
using namespace std;
struct RANGE{ll l,r;}Range[200005];
struct MINE{ll v,w;}Mine[200005];
ll n,m,sum1[200005]={0},sum2[200005]={0};
ll minn=1e18,S;
ll Check(ll W)
{
	memset(sum1,0,sizeof(sum1));
	memset(sum2,0,sizeof(sum2));
	for(ll i=1;i<=n;i++)
	{
		sum1[i]=sum1[i-1]+(Mine[i].w>=W);
		sum2[i]=sum2[i-1]+((Mine[i].w>=W)?Mine[i].v:0);
	}
	ll tot=0;
	for(ll i=1;i<=m;i++)
		tot+=(sum1[Range[i].r]-sum1[Range[i].l-1])*(sum2[Range[i].r]-sum2[Range[i].l-1]);
	minn=min(minn,abs(tot-S));
	return tot;
}
int main()
{
	scanf("%d%d%lld",&n,&m,&S);
	ll L=0,R=0,mid;
	for(ll i=1;i<=n;i++)
	{
		scanf("%d%d",&Mine[i].w,&Mine[i].v);
		R=max(R,Mine[i].w);
	}
	for(ll i=1;i<=m;i++)
		scanf("%d%d",&Range[i].l,&Range[i].r);
	while(L<=R)
	{
		mid=(L+R)/2;
		if(Check(mid)<=S) R=mid-1;
		else L=mid+1;
	}
	printf("%lld",minn);
	return 0;
}