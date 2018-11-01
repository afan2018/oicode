#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,k,ans[45]={0},maxx=0,stamp[45]={0},dp[4005]={0};
int DP(int x)
{
	for(int i=1;i<=2000;i++)
		dp[i]=41;
	dp[0]=0;
	int i=0;
	for(i=0;;i++)
	{
		if(dp[i]>n) break;
		for(int j=1;j<=x;j++)
			if(dp[i]+1<dp[i+stamp[j]]) dp[i+stamp[j]]=dp[i]+1;
	}
	return i-1;
}
void DFS(int dep)
{
	int last=DP(dep-1);
	if(dep>k)
	{
		if(last>maxx)
		{
			maxx=last;
			memcpy(ans,stamp,sizeof(stamp));
		}
		return;
	}
	for(int i=stamp[dep-1]+1;i<=last+1;i++)
	{
		stamp[dep]=i;
		DFS(dep+1);
	}
}
int main()
{
	cin>>n>>k;
	stamp[1]=1;
	DFS(2);
	for(int i=1;i<=k;i++)
		cout<<ans[i]<<' ';
	cout<<"\nMAX="<<maxx;
	return 0;
}