#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,blo,con,cost,sat[10005]={0},lim,dp[10005][105]={0},sum[10005]={0};
int main()
{
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	scanf("%d%d%d%d",&n,&blo,&con,&cost);
	for(int i=1;i<=n;i++)
		scanf("%d",&sat[i]),sum[i]=sum[i-1]+sat[i];
	scanf("%d",&lim);
	for(int j=1;j<=blo;j++)
		for(int i=j*con;i<=n;i++)
			dp[i][j]=max(dp[i-1][j],dp[i-con][j-1]+sum[i]-sum[i-con]);
//	cout<<dp[n][blo]<<endl;
	if(dp[n][blo]>lim) puts("Journey to the emergency.");
	else if(dp[n][blo]>=cost) puts("Poor restaurant.");
	else puts("HL is not satisfied.");
	return 0;
}
/*
10 2 2 20
6 5 2 9 8 4 7 1 4 0
50
*/