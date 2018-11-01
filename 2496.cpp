#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,r,map[5005][5005]={0},ans=0,sum[5005][5005]={0},lim=0;
int main()
{
	cin>>n>>r;
	for(int i=1,x,y,z;i<=n;i++)
	{
		cin>>x>>y>>z;
		map[++x][++y]=z;
		lim=max(lim,max(x,y));
	}
	for(int i=1;i<=lim;i++)
		for(int j=1;j<=lim;j++)
			map[i][j]+=map[i-1][j]+map[i][j-1]-map[i-1][j-1];
	for(int i=r;i<=lim;i++)
		for(int j=r;j<=lim;j++)
			ans=max(ans,map[i][j]-map[i-r][j]-map[i][j-r]+map[i-r][j-r]);
	cout<<ans;
	return 0;
}