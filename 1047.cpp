#include<iostream>
using namespace std;
int main(){
	int a[15],h,ans=0;
	for(int i=1;i<=10;i++)cin>>a[i];
	cin>>h;
	h=h+30;
	for(int i=1;i<=10;i++)if(a[i]<=h)ans++;
	cout<<ans;
	return 0;
}
