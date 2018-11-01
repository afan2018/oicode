#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int r;
	double c,s;
	const double pi=3.1415926;
	cin>>r;
	c=2*pi*r;
	s=pi*r*r;
	cout<<fixed<<setprecision(2)<<c<<" "<<s;
	return 0;
}