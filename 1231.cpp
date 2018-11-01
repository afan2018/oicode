#include<iostream>
#include<iomanip>
using namespace std;
	double f[1000001],a[1000001];
int main(){

	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	cin>>a[i];
	f[0]=0;
	for(int i=1;i<=t;i++){
		f[i]=max(f[i-1],f[i-1]+a[i]);
		if(i>=2)
		f[i]=max(f[i],f[i-2]+a[i-1]*a[i-1]);
		if(i==t)
		f[i]=max(f[i],f[i-1]+a[i]*a[i]);
	}
	cout<<fixed<<setprecision(4)<<f[t]<<endl;
	return 0;
}
