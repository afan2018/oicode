#include<iostream>
using namespace std;
int main(){
	int m,n,i,q;
	cin>>m>>n;
	for(i=m;i<=n;i++)
	{
		if(i==1) continue;
		int bj=0;
		for(q=2;q*q<=i;q++)
		{if(i%q==0) bj=1;}
		if(bj==0) cout<<i<<" ";
	}
	return 0;
}