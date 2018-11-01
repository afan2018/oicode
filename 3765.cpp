#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
struct node{ll val,fl;}P[2*100005];
ll n,Range=0,sum=0,ans=0,anss=0;
inline bool cmp(const node &a,const node &b)
{return a.val<b.val||(a.val==b.val&&a.fl<b.fl);}
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld%lld",&P[i].val,&P[n+i].val);
		sum+=P[i].val;
		P[i].fl=-1,P[i+n].fl=1;
	}
	sort(P+1,P+2*n+1,cmp);
	for(ll i=1;i<=2*n;i++)
	{
		if(P[i].fl==-1)
		{
			sum-=P[i].val;
			Range++;
		}
		else
		{
			if(ans<sum+Range*P[i].val)
			{
				ans=sum+Range*P[i].val;
				anss=P[i].val;
			}
			Range--;
		}
	}
	printf("%lld %lld",anss,ans);
	return 0;
}
