#include<iostream>
using namespace std;
int main(){
	int n,maxx,minn,a[105]={0},max=1,min=1;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	a[n+1]=a[1];a[n+2]=a[2];a[n+3]=a[3];
	maxx=a[1]+a[2]+a[3]+a[4];
	minn=maxx;
	for(int i=2;i<=n;i++)
	{
		if(a[i]+a[i+1]+a[i+2]+a[i+3]>maxx)maxx=a[i]+a[i+1]+a[i+2]+a[i+3],max=i;
		if(a[i]+a[i+1]+a[i+2]+a[i+3]<minn)minn=a[i]+a[i+1]+a[i+2]+a[i+3],min=i;
	}
	cout<<max<<' '<<min;
	return 0;
}
