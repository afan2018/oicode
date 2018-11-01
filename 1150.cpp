#include<iostream>
using namespace std;
int main(){
	long long n,i,q,sum=0,cd=1;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cd*=i;
		sum+=cd;
	}
	cout<<sum;
	return 0;
}