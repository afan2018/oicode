#include<iostream>
using namespace std;
bool a[200002]={0};
int main(){
	int sum=0,n;
	a[1]=true;
	for(int i=1;i<=60000;i++)
	if(a[i]) a[i*2+1]=1,a[i*3+1]=1;
	cin>>n;
	for(int i=1;sum<n;i++) if(a[i]==1)sum++,cout<<i<<' ';
	return 0;
}