#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
const double EPS=0.0000001;
struct node{int c,v;}sol[55];
int n,tarc;
double cc=0,ccc=0,sv=0,sn=0;
bool cmp(node a,node b)
{return a.c<b.c;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&sol[i].c);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&sol[i].v);
		sv+=sol[i].v;
	}
	scanf("%d",&tarc);
	for(int i=1;i<=n;i++)
		sn+=sol[i].c*sol[i].v;
	cc=sn/sv;
	if(fabs(cc-tarc)<=EPS) {printf("%.5lf",sv);return 0;}
	sort(sol+1,sol+n+1,cmp);
	if(cc>tarc)
	{
		for(int i=n;i>=1;i--)
		{
			ccc=(sn-sol[i].c*sol[i].v)/(sv-sol[i].v);
			if(fabs(ccc-tarc)<=EPS) {printf("%.5lf",double(sv-sol[i].v));return 0;}
			if(ccc<tarc)
			{
				double x;
				x=(double)(tarc*sv-sn)/(double)(tarc-sol[i].c);
				printf("%.5lf",(double)sv-x);
				return 0;
			}
			sv-=sol[i].v;
			sn-=sol[i].c*sol[i].v;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			ccc=(sn-sol[i].c*sol[i].v)/(sv-sol[i].v);
			if(fabs(ccc-tarc)<=EPS) {printf("%.5lf",double(sv-sol[i].v));return 0;}
			if(ccc>tarc)
			{
				double x;
				x=(double)(tarc*sv-sn)/(double)(tarc-sol[i].c);
				printf("%.5lf",(double)sv-x);
				return 0;
			}
			sv-=sol[i].v;
			sn-=sol[i].c*sol[i].v;
		}
	}
	printf("0.00000");
	return 0;
}