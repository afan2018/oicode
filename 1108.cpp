#include<iostream>
using namespace std;
long long f[55]={0};
int n,m;
int main(){
	cin>>n>>m;
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]*2;;
		if(i==m) f[i]--;
		else if(i>m) f[i]-=f[i-m-1];
	}
	cout<<f[n];
	return 0;
}
