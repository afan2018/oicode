#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
struct node{ll loc,vel;}car[300005];
ll n,tmp[300005]={0},tot=0;
bool cmp(const node &a,const node &b)
{return a.loc<b.loc;}
void MS(ll op,ll ed)
{
	if(op==ed) return;
	ll mid=(op+ed)/2;
	MS(op,mid);
	MS(mid+1,ed);
	ll lp=op,rp=mid+1,top=op;
	while(lp<=mid&&rp<=ed)
	{
		if(car[lp].vel>car[rp].vel)
		{
			tot+=(ll)mid-lp+1;
			tmp[top++]=car[rp++].vel;
		}
		else tmp[top++]=car[lp++].vel;
	}
	while(lp<=mid) tmp[top++]=car[lp++].vel;
	while(rp<=ed) tmp[top++]=car[rp++].vel;
	for(ll i=op;i<=ed;i++)
		car[i].vel=tmp[i];
}
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld%lld",&car[i].loc,&car[i].vel);
	sort(car+1,car+n+1,cmp);
	MS(1,n);
	printf("%lld",tot);
	return 0;
}