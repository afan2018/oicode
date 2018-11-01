#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const double EPS=1e-10;
int test;
double lh,ph,dis,x;
double Calc(double x)
{return ((lh*x-dis*ph)/(x-dis)+x);}
double Triple(double l,double r)
{
	double mid=0;
	while(r-l>EPS)
	{
		mid=(l+r)/2;
		double mmid=(mid+r)/2;
		if(Calc(mid)>Calc(mmid)) r=mmid;
		else l=mid;
	}
	return l;
}
int main()
{
	cin>>test;
	while(test--)
	{
		cin>>lh>>ph>>dis;
		cout<<fixed<<setprecision(3)<<Calc(Triple(0,(dis*ph)/lh))<<'\n';
	}
	return 0;
}
