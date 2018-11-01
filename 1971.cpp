#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
struct node{int A,Z;}Light[165];
int n,m,T,dp[55][165]={0},val[165][165]={0},tmp[8005]={0};
int main()
{
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n;i++) scanf("%d%d",&Light[i].A,&Light[i].Z);
	for(int i=1;i<=n;i++)
	{
		memset(tmp,0,sizeof(tmp));	
		for(int j=i;j<=n;j++)
		{
			for(int k=T*(n-i+1);k>=Light[j].A;k--)
				tmp[k]=max(tmp[k],tmp[k-Light[j].A]+Light[j].Z);
			val[i][j]=tmp[T*(j-i+1)];
		}
	}
	for(int i=1;i<=n;i++) dp[1][i]=val[1][i];
	for(int i=2;i<=m;i++) 
		for(int j=i;j<=n;j++)
			for(int k=i-1;k<j;k++)
				dp[i][j]=max(dp[i][j],dp[i-1][k]+val[k+1][j]);
	printf("%d",dp[m][n]);
	return 0;
}
