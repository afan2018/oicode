#include<iostream>
using namespace std;
long long n,q,k;
long long phi(long long n,long long q){
	k=n/2;
	if(n==1)return 1;
	if(q<=k)return n-k+phi(k,k-q+1);
	if(q>k)return phi(n-k,n-q+1);
}
int main(){
	cin>>n>>q;
	cout<<phi(n,q);
	return 0;
}