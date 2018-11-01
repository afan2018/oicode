#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	int n,val[1005]={0},dp[10005]={0},tot;
	cin>>n>>tot;
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++)
		cin>>val[i];
	for(int i=1;i<=n;i++)
		for(int j=val[i];j<=tot;j++)
			dp[j]=min(dp[j],dp[j-val[i]]+1);
	for(int i=1;i<=tot;i++) 
		if(dp[i]==0x3f3f3f3f) cout<<dp[i]<<endl;
			else cout<<dp[i]<<endl;
	return 0;
}