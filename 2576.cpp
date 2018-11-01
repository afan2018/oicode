#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[15][32768]={0},S[15][32768]={0},n,m,ans=0;
void Get(int x,int foo)
{
	for(int i=0;i<(1<<m);i++)
	{
		if((i&(i<<1)||(i&(i>>1))||(i&foo))) continue;
		S[x][++S[x][0]]=i; 
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++)
	{
		int foo=0;
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&x);
			foo=foo*2+(!x);
		}
		Get(i,foo);
	}
	for(int i=1;i<=S[1][0];i++) dp[1][i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=S[i][0];j++)
			for(int k=1;k<=S[i-1][0];k++)
				if(!(S[i][j]&S[i-1][k])) dp[i][j]+=dp[i-1][k];
	for(int i=1;i<=S[n][0];i++) ans=(ans+dp[n][i])%100000000;
	printf("%d",ans);
	return 0;
}