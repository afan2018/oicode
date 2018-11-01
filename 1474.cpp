#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
struct node{int val,W,V;}Gift[400];
int V,G,n,dp[2][400][400]={0};
int main()
{
	scanf("%d%d%d",&V,&G,&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&Gift[i].val,&Gift[i].W,&Gift[i].V);
	for(int i=1;i<=n;i++)
		for(int j=V;j>=0;j--)
			for(int k=G;k>=0;k--)
				if(j>=Gift[i].W&&k>=Gift[i].V) dp[i%2][j][k]=max(dp[(i+1)%2][j][k],dp[(i+1)%2][j-Gift[i].W][k-Gift[i].V]+Gift[i].val);
				else dp[i%2][j][k]=dp[(i+1)%2][j][k];
	printf("%d",dp[n%2][V][G]);
	return 0;
}
