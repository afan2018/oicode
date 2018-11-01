#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MOD=100000000;
string A,B;
char buffer[5005];
int dp[5005][5005]={0},la,lb,sum=0,ans=0,f[5005][5005]={0};
int main()
{
	scanf("%s",buffer);
	A=buffer;
	la=A.length()-1;
	A=' '+A;
	scanf("%s",buffer);
	B=buffer;
	lb=B.length()-1;
	B=' '+B;
	for(int i=0;i<=lb;i++) f[0][i]=1;
	for(int i=0;i<=la;i++)f[i][0]=1;
	for(int i=1;i<=la;i++)
		for(int j=1;j<=lb;j++)
		{
			f[i][j]=f[i-1][j],dp[i][j]=dp[i-1][j];
			if(dp[i][j-1]>dp[i][j]) dp[i][j]=dp[i][j-1],f[i][j]=f[i][j-1];
			else if(dp[i][j-1]==dp[i][j]) f[i][j]=(f[i][j]+f[i][j-1])%MOD;
			if(dp[i][j]==dp[i-1][j-1]) f[i][j]=((f[i][j]-f[i-1][j-1])%MOD+MOD)%MOD;
			if(A[i]==B[j])
			{
				if(dp[i][j]<dp[i-1][j-1]+1) dp[i][j]=dp[i-1][j-1]+1,f[i][j]=f[i-1][j-1];
				else if(dp[i-1][j-1]+1==dp[i][j]) f[i][j]=(f[i][j]+f[i-1][j-1])%MOD;
			}
		}
	printf("%d\n%d",dp[la][lb],f[la][lb]);
	return 0;
}