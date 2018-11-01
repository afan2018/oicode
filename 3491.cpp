#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
struct node{ll x1,y1,x2,y2;}a[1005];
ll n,tot=0;
void Add(ll x1,ll y1,ll x2,ll y2)
{a[++tot].x1=x1,a[tot].y1=y1,a[tot].x2=x2,a[tot].y2=y2;}
void Cut(ll num,ll x1,ll y1,ll x2,ll y2,ll fl)
{
	if(fl==0)
	{
		ll lx=max(x1,a[num].x1);
		ll rx=min(x2,a[num].x2);
		if(a[num].x1<lx) Add(a[num].x1,a[num].y1,lx,a[num].y2);
		if(a[num].x2>rx) Add(rx,a[num].y1,a[num].x2,a[num].y2);
		Cut(num,lx,y1,rx,y2,1);
	}
	else
	{
		ll ty=max(y1,a[num].y1);
		ll by=min(y2,a[num].y2);
		if(a[num].y1<ty) Add(x1,a[num].y1,x2,ty);
		if(a[num].y2>by) Add(x1,by,x2,a[num].y2);
	}
}
int main()
{
	scanf("%lld%lld%lld%lld%lld",&n,&a[1].x1,&a[1].y1,&a[1].x2,&a[1].y2);
	swap(a[1].y1,a[1].y2);
	tot++;
	ll x1,y1,x2,y2;
	for(ll i=2;i<=n;i++)
	{
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		swap(y1,y2);
		ll tmp=tot;
		for(ll j=1;j<=tot;j++)
		{
			if(x1>=a[j].x2||x2<=a[j].x1||y1>=a[j].y2||y2<=a[j].y1) continue;
			Cut(j,x1,y1,x2,y2,0);
			a[j]=a[tmp],a[tmp]=a[tot];
			tmp--;tot--;j--;
		}
		Add(x1,y1,x2,y2);
	}
	ll sum=0;
	for(ll i=1;i<=tot;i++)
		sum+=(a[i].x2-a[i].x1)*(a[i].y2-a[i].y1);
	printf("%lld",sum);
	return 0;
}