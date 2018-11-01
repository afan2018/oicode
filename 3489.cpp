#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
bool dp[2005][2005]={0};
int n,sum,seq[2005]={0},minn=0x3f3f3f3f;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>seq[i],sum+=seq[i];
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=sum;j>=0;j--)
			for(int k=sum;k>=0;k--)
				if(dp[j][k])
					dp[j+seq[i]][k]=dp[j][k+seq[i]]=true;
	for(int i=sum;i>=0;i--)
		for(int j=sum;j>=0;j--)
			if(dp[i][j])
				minn=min(minn,max(i,max(j,sum-i-j)));
	cout<<minn;
	return 0;
}