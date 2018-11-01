#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
struct node{ll hap,unh;}oier[1005];
ll n,val[1005][1005]={0},tmp=0,ans=0,cnt=0;
inline bool cmp(const ll &a,const ll &b)
{return a>b;}
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&oier[i].hap);
		val[1][i]=oier[i].hap;
	}
	for(ll i=1;i<=n;i++)
		scanf("%lld",&oier[i].unh);
	for(ll i=2;i<=n;i++)
		for(ll j=1;j<=n;j++)
			val[i][j]=val[i-1][j]-oier[j].unh;
	for(ll i=1;i<=n;i++)
	{
		tmp=0;
		sort(val[i]+1,val[i]+n+1,cmp);
		for(ll j=1;j<=i;j++)
		{
			tmp+=val[i][j];
			if(tmp>=ans)
			{
				cnt=i;
				ans=tmp;
			}
		}
	}
	printf("%lld\n%lld",ans,cnt);
	return 0;
}
/*
6
10 10 10 10 10 9
2 2 2 2 2 3 
*/