#include<iostream>
#include<iomanip>
using namespace std;
double max(int x,int y,int z)
{
	double maxx=0;
	if(x>=y) maxx=x;
	else maxx=y;
	if(z>maxx) maxx=z;
	return maxx;
}
int main(){
	int a,b,c;
	double m;
	cin>>a>>b>>c;
	m=max(a,b,c)/(max(a+b,b,c)*max(a,b,b+c));
	cout<<fixed<<setprecision(3)<<m;
	return 0;
}
