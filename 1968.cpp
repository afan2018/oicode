#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,m,r,c,num[3005][3005]={0},ans=0;
int main()
{
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&r,&c);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&num[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			num[i][j]+=num[i-1][j]+num[i][j-1]-num[i-1][j-1];
	for(int i=r;i<=n;i++)
		for(int j=c;j<=m;j++)
			ans=max(ans,num[i][j]-num[i-r][j]-num[i][j-c]+num[i-r][j-c]);
	cout<<ans;
	return 0;
}
