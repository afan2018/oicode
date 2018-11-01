#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
long long n,f[25]={0};
int main()
{
	cin>>n;
	f[1]=0,f[2]=1;
	for(long long i=3;i<=n;i++)
		f[i]=(i-1)*(f[i-1]+f[i-2]);
	cout<<f[n];
	return 0;
}
