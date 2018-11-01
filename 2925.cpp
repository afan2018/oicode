#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{long long x,y;}sta,tar;
long long esc[100005]={0},n,m;
long long afanbs(long long x)
{return x>0?x:-x;}
long long BS(long long op,long long ed,long long x1)
{
	long long mid,k;
	while(op<=ed)
	{
		mid=(op+ed)/2;
		if(esc[mid]>=x1)k=mid,ed=mid-1;
		else op=mid+1;
	}
	return op-1;
}
int main()
{
	std::ios::sync_with_stdio(false); 
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)	scanf("%lld",&esc[i]);
	sort(esc+1,esc+n+1);
	scanf("%lld",&m);
	while(m--)
	{
		scanf("%lld%lld%lld%lld",&sta.x,&sta.y,&tar.x,&tar.y);
		if(sta.y*tar.y>=0)
		{
			printf("%lld\n",afanbs(sta.x-tar.x)+afanbs(sta.y-tar.y));
			continue;
		}
		long long door=BS(1,n,sta.x);
		long long disa,disb,dis1=(1<<30),dis2=(1<<30);
		if (door>0)
		{
		 	disa=afanbs(sta.x-esc[door])+afanbs(sta.y);
		    disb=afanbs(tar.x-esc[door])+afanbs(tar.y);
		    dis1=disa+disb;
		}
		if(door<n) 
		{
		 	disa=afanbs(sta.x-esc[door+1])+afanbs(sta.y);
		    disb=afanbs(tar.x-esc[door+1])+afanbs(tar.y);
		    dis2=disa+disb;
		}
		printf("%lld\n",min(dis1,dis2));
	}
	return 0;
}