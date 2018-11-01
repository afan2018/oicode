#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int x,y,val,mul;}my[2005];
int n,deg,smul[2005]={0},sval[2005]={0};
double slo=0,dp[2005]={0};
bool cmp(node a,node b)
{return a.y-slo*a.x>b.y-slo*b.x;}
double Getsum(int op,int ed)
{return (double)(sval[ed]-sval[op])*(smul[ed]-smul[op])/(double)(ed-op);}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d%d",&my[i].x,&my[i].y,&my[i].val,&my[i].mul);
	scanf("%d",&deg);
	slo=tan(deg*M_PI/180);
	sort(my+1,my+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		sval[i]=sval[i-1]+my[i].val;
		smul[i]=smul[i-1]+my[i].mul;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			dp[i]=max(dp[i],dp[j]+Getsum(j,i));
	cout<<fixed<<setprecision(3)<<dp[n];
	return 0;
}
/*
3
1 3 3 1
2 1 2 2
3 4 2 1
45
*/