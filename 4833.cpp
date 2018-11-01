#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,dp[255][255]={0},maxx=0;
int main()
{
	scanf("%d",&n);
	memset(dp,0xcf,sizeof(dp));
	for(int i=1;i<=n;i++)
		scanf("%d",&dp[i][i]);
	for(int k=2;k<=n;k++)//length
		for(int i=1;i<=n-k+1;i++)//start
		{
			int pos=i+k-1;//end
			for(int j=i;j<pos;j++)//enum
				if(dp[i][j]!=0xcfcfcfcf&&dp[i][j]==dp[j+1][pos])
					dp[i][pos]=max(dp[i][pos],dp[i][j]+1);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			maxx=max(maxx,dp[i][j]);
	printf("%d",maxx);
	return 0;
}