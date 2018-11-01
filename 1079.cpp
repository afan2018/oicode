#include<iostream>
using namespace std;
int main(){
	long long n,max=-(1<<30),sum=0,x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(sum<=0)sum=x;
		  else sum+=x;
		if(sum>max)max=sum;
	}
	cout<<max;
	return 0;
}