#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const double EPS (0.0001);
struct node{double x,y;}P[100005];
double a,b,d,seq[100005]={0},Range=0,Q[100005]={0};
int n,ans=0,L=1,R=0,cnt=0;
double Abs(double x)
{return x>0?x:-x;}
int main()
{
	scanf("%lf%lf%lf%d",&a,&b,&d,&n);
	for(int i=1;i<=n;i++)
	{
		double x,y;
		scanf("%lf%lf",&x,&y);
		a?seq[i]=((-a)*x+(-b)*y)/b:seq[i]=y;
	}
	sort(seq+1,seq+n+1);
	Range=a?2*sqrt(((a*a)/(b*b))*(d*d)+d*d):2*d;
	for(int i=1;i<=n;i++)
	{
		Q[++R]=seq[i],cnt++;
		while(L<=R&&Abs(Q[L]-seq[i])-Range>EPS) L++,cnt--;
		ans=max(ans,cnt);
	}
	printf("%d",ans);
	return 0;
}