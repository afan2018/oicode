#include<iostream>
using namespace std;
int n,k;
long long S(long n,long k)
{
	if((n<k)||(k==0))return 0;
	if((k==1)||(k==n))return 1;
	return S(n-1,k-1)+k*S(n-1,k);
}
int main(){
	cin>>n>>k;
	cout<<S(n,k);
	return 0;
}
