#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{long long val,pos;}med[2000005];
long long path[2000005]={0},n,m,dp[2000005]={0},val[2000005]={0};
inline bool cmp(const node &a,const node &b)
{return a.pos<b.pos;}
int main()
{
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>med[i].val>>med[i].pos;
	sort(med+1,med+n+1,cmp);
	med[0].pos=0;
	path[0]=0;
	for(long long i=1;i<=n;i++)
	{
		if(med[i].pos-med[i-1].pos>17) 
			path[i]=path[i-1]+18;
		else path[i]=path[i-1]+med[i].pos-med[i-1].pos;
	}
	for(long long i=1;i<=n;i++)
		val[path[i]]+=med[i].val;
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	long long ans=0;
	for(long long i=4;i<=path[n];i++)
	{
		long long tmp;
		if(i>=7) tmp=max(dp[i-4],dp[i-7]);
		else tmp=dp[i-4];
		if(tmp==-1) continue;
		dp[i]=tmp+val[i];
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}