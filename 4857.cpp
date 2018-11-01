#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<unistd.h>
using namespace std;
int dp[305][305][305],n,K,ans=0;
string A,B;
char buffer[305];
int main()
{
	scanf("%d%d",&n,&K);
	scanf("%s",buffer);
	A=buffer;
	A=' '+A;
	scanf("%s",buffer);
	B=buffer;
	B=' '+B;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=0;k<=K;k++)
			{
				if(A[i]==B[j]) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+1);
				else if(k>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-1]+1);
				ans=max(ans,dp[i][j][K]);
			}
	printf("%d",ans);
	return 0;
}
