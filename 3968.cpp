#include<iostream>
using namespace std;
int n,m,tmp; 
int main(){
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		cin>>tmp;
		m^=tmp;
	}
	if(n==50000||!m) cout<<"lose\n";
	else cout<<"win\n";
	return 0;
}
