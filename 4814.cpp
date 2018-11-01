#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{long long fr,to,val;} edge[4000005];
long long n,num[2005]={0},cnt=0,fa[400005]={0},ccnt=0,ans=0;
bool cmp(const node &x,const node &y)
{return x.val>y.val;}
long long Getfa(long long x)
{
	if(fa[x]==x) return x;
	return fa[x]=Getfa(fa[x]);
}
void K()
{
	for(long long i=1;i<=n;i++) fa[i]=i;
	sort(edge+1,edge+cnt+1,cmp);
	for(long long i=1;i<=cnt;i++)
	{
		long long a=Getfa(edge[i].fr),b=Getfa(edge[i].to);
		if(a==b) continue;
		ccnt++;
		fa[a]=b;
		ans+=edge[i].val;
		if(ccnt==n-1)
		{
			printf("%lld",ans);
			return;
		}
	}
}
int main()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++) scanf("%lld",&num[i]);
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=n;j++)
			if(i!=j)
			{
				edge[++cnt].to=j;
				edge[cnt].fr=i;
				edge[cnt].val=num[i]^num[j];
			}
	K();
	return 0;
}