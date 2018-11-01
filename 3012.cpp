#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
int k,n;
ll dp[150][150]={0},unit[150][150]={0};
void Mul(ll a[][150],ll b[][150])
{
	ll c[150][150]={0};
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
			for(int h=1;h<=k;h++)
				c[i][j]=(c[i][j]+a[i][h]*b[h][j])%100003;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
			a[i][j]=c[i][j];
}
int main()
{
	cin>>n>>k;
	for(int i=2;i<=k;i++) dp[i][i-1]=1;
	for(int i=1;i<=k;i++) dp[1][i]=1,unit[i][i]=1;
	int tmp=n;
	while(tmp)
	{
		if(tmp&1) Mul(unit,dp);
		Mul(dp,dp);
		tmp/=2;
	}
	cout<<unit[1][1]%100003;
	return 0;
}