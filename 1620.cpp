#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const double EPS=1e-11;
long double a,b,m,n,p;
long double f(double x)
{return pow(m,x)+pow(n,x)-pow(p,x);}
double afanbs(double x)
{return x>0?x:-x;}
int main()
{
	cin>>m>>n>>p>>a>>b;
	if(f(a)*f(b)>0) {puts("NO");return 0;}
	while(afanbs(a-b)>EPS)
	{
		double fa=f(a),mid=(a+b)/2,fmid=f(mid);
		if(fa*fmid<0) b=mid;
		else a=mid;
	}
	cout<<fixed<<setprecision(8)<<(a+b)/2<<endl;
	cout<<fixed<<setprecision(15)<<f((a+b)/2)<<endl;
	return 0;
}