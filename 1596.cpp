#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int w[205]={0},v[205]={0},dp[2050]={0},tot,n;
int main()
{
	cin>>tot>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i]>>v[i];
	for(int i=1;i<=n;i++)
		for(int j=w[i];j<=tot;j++)
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
	int afan=0;
	for(int i=1;i<=tot;i++) afan=max(afan,dp[i]);
	cout<<afan;
	return 0;
}
