#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int sum[2005]={0},dp[2005][2005]={0},seq[2005]={0},n,flag=0;
int main()
{
	cin>>n>>flag;
	for(int i=1;i<=n;i++)
	{
		cin>>seq[i];
		sum[i]=sum[i-1]+seq[i];
		dp[i][i]=seq[i];
	}
	for(int l=2;l<=n;l++)
		for(int i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			dp[i][j]=max(seq[i]+sum[j]-sum[i]-dp[i+1][j],seq[j]+sum[j-1]-sum[i-1]-dp[i][j-1]);
		}
	if(flag) cout<<dp[1][n];
	else cout<<sum[n]-dp[1][n];
	return 0;
}