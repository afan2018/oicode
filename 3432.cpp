#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
struct node{double x,y;}sit[1000005];
double getarea(node a,node c,node b)
{
	double k;
	k=((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y))/2;
	return k;
}
int main(){
	int n;
	node a,b,c,cen;
	cin>>n;
	cin>>a.x>>a.y>>b.x>>b.y;
	double sumx=0,sumy=0,suma=0,area=0;
	for(int i=3;i<=n;i++)
	{
		cin>>c.x>>c.y;
		cen.x=a.x+b.x+c.x;
		cen.y=a.y+b.y+c.y;
		area=getarea(a,b,c);
		suma+=area;
		sumx+=cen.x*area;
		sumy+=cen.y*area;
		b=c;
	}	
	cout<<fixed<<setprecision(2)<<sumx/suma/3<<' '<<sumy/suma/3;
	return 0;
}