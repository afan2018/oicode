#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int seq[355]={0},ha[5]={0},n,m,dp[45][45][45][45];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>seq[i];
	for(int i=1,x;i<=m;i++)
	{
		cin>>x;
		ha[x]++;
	}
	for(int f=0;f<=ha[1];f++)
		for(int u=0;u<=ha[2];u++)
			for(int c=0;c<=ha[3];c++)
				for(int k=0;k<=ha[4];k++)
				{
					if(f>0) dp[f][u][c][k]=max(dp[f][u][c][k],dp[f-1][u][c][k]);
					if(u>0) dp[f][u][c][k]=max(dp[f][u][c][k],dp[f][u-1][c][k]);
					if(c>0) dp[f][u][c][k]=max(dp[f][u][c][k],dp[f][u][c-1][k]);
					if(k>0) dp[f][u][c][k]=max(dp[f][u][c][k],dp[f][u][c][k-1]);
					dp[f][u][c][k]+=seq[f+2*u+3*c+4*k+1];
				}
	cout<<dp[ha[1]][ha[2]][ha[3]][ha[4]];
	return 0;
}