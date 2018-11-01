#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
struct Point{double x,y;}P[1005];
int n;
double dis[1005][1005]={0},dp[1005][1005]={0},ans=1e30;
inline bool cmp(const Point &a,const Point &b)
{return a.x<b.x;}
inline double Getdis(int x,int y)
{return sqrt((P[x].x-P[y].x)*(P[x].x-P[y].x)+(P[x].y-P[y].y)*(P[x].y-P[y].y));}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf%lf",&P[i].x,&P[i].y);
	sort(P+1,P+n+1,cmp);	
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			dis[i][j]=Getdis(i,j);
			dp[i][j]=1e30;			
		}

	dp[1][2]=dis[1][2];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			dp[i][j+1]=min(dp[i][j+1],dp[i][j]+dis[j][j+1]);
			dp[j][j+1]=min(dp[j][j+1],dp[i][j]+dis[i][j+1]);
		}
	for(int i=1;i<n;i++) ans=min(ans,dp[i][n]+dis[i][n]);
	printf("%.2lf",ans);
	return 0;
}
