#include<iostream>
using namespace std;
int main(){
	int n,a[105]={0},max=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	max=a[1];
	for(int i=1;i<=n;i++)
	{
		if(a[i]>max)max=a[i],ans=i;
	}
	cout<<max<<' '<<ans;
	return 0;
}
