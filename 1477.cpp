#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
char map[55][55];
ll dp[55][55]={0},n,m;
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin>>map[i][j];
	dp[1][1]=(1ll<<n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(map[i][j]=='*')
			{
				dp[i+1][j]+=dp[i][j]/2;
				dp[i+1][j+1]+=dp[i][j]/2;
			}
			else dp[i+2][j+1]+=dp[i][j];
	ll foo=1ll<<n;
	if(dp[n+1][m+1]==0) {puts("0/1");return 0;}
	while(dp[n+1][m+1]%2==0) {dp[n+1][m+1]/=2 ;foo/=2;}
	printf("%lld/%lld",dp[n+1][m+1],foo);
	return 0;
}