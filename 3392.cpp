#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,k,h[5001]={0},dp[5001]={0};
int main(void)
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>h[i];
	dp[1]=1;
	int	x,y,fr,to;
	for(int i=2;i<=n;i++)
	{
		dp[i]=0x7f7f7f7f;
		fr=max(1,i-k);
		to=i-1;
		double mink=0x7f7f7f7f;
		for(int j=to;j>=fr;--j)
		{
			y=h[i]-h[j];
			x=i-j;
			double newk=(double)y/(double)x;
			mink=min(newk,mink);
			if(mink>=newk) dp[i]=min(dp[j]+1,dp[i]);
		}
	}
	cout<<dp[n];
	return 0;
}