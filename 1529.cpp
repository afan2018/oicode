#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{   double a,b,d;
    char c;
    cin>>a>>b>>c;
    if(c=='+') d=a+b;
    if(c=='-') d=a-b;
    if(c=='*') d=a*b;
    if(c=='/'&&b!=0) d=a/b;
	if(c=='/'&&b==0) cout<<"error";
	else cout<<fixed<<setprecision(1)<<d;
	return 0;
}