#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int L[1005]={0},R[1005]={0},dp[1005][1005][2]={0},n,lcnt=0,rcnt=0;
int main()
{
	cin>>n;
	for(int i=1,x;i<=n;i++)
	{
		cin>>x;
		if(x>0) R[++rcnt]=x;
		else L[++lcnt]=-x;
	}
	sort(L+1,L+lcnt+1);
	sort(R+1,R+rcnt+1);
	for(int i=1;i<=lcnt;i++)
	{
		dp[i][0][0]=dp[i-1][0][0]+(L[i]-L[i-1])*(lcnt+rcnt-(i-1));
		dp[i][0][1]=dp[i][0][0]+L[i]*(lcnt+rcnt-(i-1));
	}
	for(int i=1;i<=rcnt;i++)
	{
		dp[0][i][1]=dp[0][i-1][1]+(R[i]-R[i-1])*(lcnt+rcnt-(i-1));
		dp[0][i][0]=dp[0][i][1]+R[i]*(lcnt+rcnt-(i-1));
	}
	for(int i=1;i<=lcnt;i++)
		for(int j=1;j<=rcnt;j++)
		{
			dp[i][j][0]=min(dp[i-1][j][0]+(L[i]-L[i-1])*(lcnt-(i-1)+rcnt-j),dp[i-1][j][1]+(L[i]+R[j])*(lcnt-(i-1)+rcnt-j));
			dp[i][j][1]=min(dp[i][j-1][1]+(R[j]-R[j-1])*(rcnt-(j-1)+lcnt-i),dp[i][j-1][0]+(L[i]+R[j])*(rcnt-(j-1)+lcnt-i));
		}
	cout<<min(dp[lcnt][rcnt][0],dp[lcnt][rcnt][1]);
	return 0;
}