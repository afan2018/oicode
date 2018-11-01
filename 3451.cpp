#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int dp[105][105]={0},n,m,t[105][3]={0};
bool C(int lim)
{
	memset(dp,0xcf,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<=j&&k*t[i][1]<=lim;k++)
				dp[i][j]=max(dp[i][j],dp[i-1][j-k]+(lim-k*t[i][1])/t[i][2]);
	return dp[n][m]>=m;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>t[i][1]>>t[i][2];
	int l=0,r=1e6,mid,ans=-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(C(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}