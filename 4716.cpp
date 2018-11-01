#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node{int p,j;}afan[1005];
int t,n,dp[1005][1005]={0},val[1005][1005]={0},sum=0;
string peo;
bool cmp(node x,node y)
{
	if(x.p!=y.p) return x.p>y.p;
	return x.j<y.j;
}
int main()
{
//	freopen("spicy.in","r",stdin);
//	freopen("spicy.out","w",stdout);
	cin>>n;
	sum=0;
	cin>>peo;
	for(int i=1;i<=n;i++)
		cin>>afan[i].p>>afan[i].j,sum+=afan[i].p;
	sort(afan+1,afan+n+1,cmp);
	int hh=(peo[0]=='a');
	for(int i=1;i<=n-hh;i++)
		for(int j=1;j<=(i+1)/2;j++)
		{
			if(dp[i-1][j]>dp[i-1][j-1]+afan[i+hh].j)
			{
				dp[i][j]=dp[i-1][j];
				val[i][j]=val[i-1][j];
			}
			else if(dp[i-1][j]==dp[i-1][j-1]+afan[i+hh].j)
			{
				dp[i][j]=dp[i-1][j];
				val[i][j]=min(val[i-1][j],val[i-1][j-1]+afan[i+hh].p);
			}
			else
			{
				dp[i][j]=dp[i-1][j-1]+afan[i+hh].j;
				val[i][j]=val[i-1][j-1]+afan[i+hh].p;
			}
		}
	cout<<sum-val[n-hh][(n-hh+1)/2]<<' '<<dp[n-hh][(n-hh+1)/2]<<endl;
	return 0;
}
