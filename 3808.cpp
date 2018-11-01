#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;
const double EPS=0.0001;
struct node{double x,R;}circ[10];
double ed,H;
inline bool cmp(const node &a,const node &b)
{return a.x<b.x||(a.x==b.x&&a.R>b.R);}
inline double sq(double x)
{return x*x;}
bool Check(double x)
{
	double Reach=0;
	for(int i=1;i<=7;i++)
		if(circ[i].x-sqrt(sq(circ[i].R+x)-sq(H))<=Reach)
			Reach=max(Reach,circ[i].x+sqrt(sq(circ[i].R+x)-sq(H)));
	if(Reach>=ed) return true;
	return false;
}
int main()
{
	scanf("%lf%lf",&H,&ed);
	for(int i=1;i<=7;i++) scanf("%lf%lf",&circ[i].x,&circ[i].R);
	sort(circ+1,circ+7+1,cmp);
	double L=0.0,R=10001.0,mid,ans;
	while(R-L>EPS)
	{
		mid=(R+L)/2;
		if(Check(mid)) R=mid;
		else L=mid;
	}
	printf("%.2lf",L);
	return 0;
}
