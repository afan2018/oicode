#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,cnt=0;
double val[1005]={0},maxx=0,m;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>val[i];
	cin>>m;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			maxx=max(maxx,(int)(m/val[i])*val[j]-(int)(m/val[i])*val[i]);
			if((int)(m/val[i])*val[j]-(int)(m/val[i])*val[i]>0) cnt++;
		}	
	cout<<fixed<<setprecision(3)<<maxx<<endl<<cnt/double(((n*n-n)/2));
	return 0;
}
