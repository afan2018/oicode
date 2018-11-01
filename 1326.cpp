#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[50005]={0},n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	cout<<endl;
	for(int i=n;i>=1;i--)cout<<a[i]<<' ';
	return 0;
}
