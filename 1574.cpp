#include<iostream>
using namespace std;
int main(){
	int n,met[45]={0};
	cin>>n;
	met[1]=1,met[2]=2;
	for(int i=3;i<=n;i++)
		met[i]=met[i-1]+met[i-2];
	cout<<met[n];
	return 0;
}
