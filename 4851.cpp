#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
struct node{ll to,nx;}edge[200005];
ll h[200005]={0},cnt=0,n,k,val[200005]={0},bur[200005]={0},foo[200005]={0},ccnt,son[200005]={0},ans=0;
bool cmp(const ll a,const ll b)
{return a>b;}
void Add(ll x,ll y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
void DFS1(ll x)
{
	ll maxx=0;
	for(ll i=h[x];i;i=edge[i].nx)
	{
		ll to=edge[i].to;
		DFS1(to);
		if(bur[to]>maxx) {maxx=bur[to];son[x]=to;}
	}
	bur[x]=maxx+val[x];
}
void DFS2(ll x)
{
	for(ll i=h[x];i;i=edge[i].nx)
	{
		ll to=edge[i].to;
		if(to!=son[x]) foo[++ccnt]=bur[to];
		DFS2(to);
	}
}
int main()
{
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++) scanf("%lld",val+i);
	for(ll i=1,x,y;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		Add(x,y);
	}
	DFS1(1);
	ccnt=1;
	foo[1]=bur[1];
	DFS2(1);
	sort(foo+1,foo+ccnt+1,cmp);
	for(ll i=1;i<=k;i++) ans+=foo[i];
	printf("%lld",ans);
	return 0;
}
