#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int x[10005]={0},n,m,dp[10005]={0},val[100005]={0};
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i<=m;i++)
		cin>>val[i];
	sort(x+1,x+n+1);
	for(int i=m-1;i>=1;i--)
		val[i]=min(val[i],val[i+1]);
	val[0]=val[1];
	fill(dp+1,dp+n+1,0x3f3f3f3f);
	dp[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			dp[i]=min(dp[i],dp[j]+val[x[i]-x[j+1]+1]);
	cout<<dp[n];
	return 0;
}

