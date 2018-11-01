#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,f[5]={0};
int main(){
	cin>>n;
	f[1]=1,f[2]=2,f[3]=5;
	for(int i=4;i<=n;i++)
		f[i%4]=(2*f[(i-1)%4]+f[(i-3)%4])%10000;
	cout<<f[n%4];
	return 0;
}
