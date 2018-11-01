#include<iostream>
#include<cstring>
using namespace std;
int map[1005][1005]={{0},{0}},n,dp[1005][1005]={{0},{0}},maxx=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		string str;
		char buffer[1005];
		scanf("%s",buffer);
		str=buffer;
		for(int j=0;j<n;j++)
			map[i][j+1]=str[j]-'0';
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(map[i][j])
			{
				dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
				maxx=max(dp[i][j],maxx);
			}
	cout<<maxx*maxx<<endl;
	return 0;
}
