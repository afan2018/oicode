#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const double EPS=1e-11;
struct node{double a,b,c;}func[10005];
int test,n;
double Calc(double x)
{
	double maxx=-0x7f7f7f7f;
	for(int i=1;i<=n;i++)
		maxx=max(maxx,func[i].a*x*x+func[i].b*x+func[i].c);
	return maxx;
}
double Triple(double l,double r)
{
	double mid,mmid;
	while(r-l>EPS)
	{
		mid=(l+r)/2;
		mmid=(mid+r)/2;
		if(Calc(mid)<=Calc(mmid)) r=mmid;
		else l=mid;
	}
	return l;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>test;
	while(test--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>func[i].a>>func[i].b>>func[i].c;
		cout<<fixed<<setprecision(4)<<Calc(Triple(0,1000))<<'\n';
	}
	return 0;
}
