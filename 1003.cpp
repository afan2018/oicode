#include<iostream>
using namespace std;
int main(){
	int n,poker[55],m[200];
	cin>>n;
	for(int i=1;i<=n;i++)m[i]=i;
	int t=0,b=n;
	for(int i=1;i<=n;i++){
		t++;
		poker[m[t]]=i;
		t++;
		b++;
		m[b]=m[t];
		t++;
		b++;
		m[b]=m[t];
	}
	for(int i=1;i<=n;i++)cout<<poker[i]<<' ';
	return 0;
}