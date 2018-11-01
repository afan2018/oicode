#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	int n,tot,val[10005]={0},tim[10005]={0},dp[1005]={0};
	cin>>n>>tot;
	for(int i=1;i<=n;i++)
		cin>>val[i]>>tim[i];
	for(int i=1;i<=n;i++)
		for(int j=tot;j>=1;j--)
		{
			if(tim[i]>j) continue;
			dp[j]=max(dp[j],dp[j-tim[i]]+val[i]);
		}
	cout<<dp[tot];
	return 0;
}
/*
3
5
1 2
5 5
4 3
*/