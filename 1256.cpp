#include<iostream>
#include<iomanip>
using namespace std;
double a,b,c,d;
double calc(double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}
void div(double x1,double x2){
	double x0,y1,y2,y0;
	x0=(x1+x2)/2;
	y1=calc(x1);y2=calc(x2);y0=calc(x0);
	if(x2-x1<0.00001&&y2*y1<0){
		cout<<fixed<<setprecision(2)<<x0<<' ';
		return;
	}
	if(y1*y0<0)div(x1,x0);
	if(y2*y0<0)div(x0,x2);
	if(y1==0)cout<<fixed<<setprecision(2)<<x1<<' ';
	if(y2==0)cout<<fixed<<setprecision(2)<<x2<<' ';
}
int main(){
	cin>>a>>b>>c>>d;
	for(int i=-100;i<=100;i++)
	{
		if(calc(i)==0)cout<<fixed<<setprecision(2)<<double(i)<<' ';
		else if(calc(i)*calc(i+1)<0)div(i,i+1);
	}
	return 0;
}