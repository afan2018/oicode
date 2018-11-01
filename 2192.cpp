#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double ans,x11,y11,x22,y22,r11,r22;
int main(){
	cin>>x11>>y11>>r11>>x22>>y22>>r22;
	ans=2*sqrt((x11-x22)*(x11-x22)+(y11-y22)*(y11-y22));
	cout<<fixed<<setprecision(6)<<ans;
	return 0;
}
