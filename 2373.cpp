#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int sx,sy,n;
double DFS(double x,double y,int hh)
{
	if(hh==1) return (x>y)?(x/y):(y/x);
	double ret=double(1e30);
	double unit=(double)1/hh;
	for(int i=1;i<=hh/2;i++)
	{
		double val1=max(DFS(x*unit*i,y,i),DFS(x*unit*(hh-i),y,hh-i));
		double val2=max(DFS(x,y*unit*i,i),DFS(x,y*unit*(hh-i),hh-i));
		ret=min(ret,min(val1,val2));
	}
	return ret;
}
int main()
{
	cin>>sx>>sy>>n;
	cout<<fixed<<setprecision(6)<<DFS(double(sx),double(sy),n);
	return 0;
}