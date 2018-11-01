#include<iostream>
#include<algorithm>
using namespace std;
int a[200005]={0};
int main(){
	int n,j=1;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n+1;i++){
		if(a[i]==a[i-1])j++;
		else {
			cout<<a[i-1]<<' '<<j<<endl;
			j=1;
		}
	}
	return 0;
}
