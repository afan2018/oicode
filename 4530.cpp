#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		scanf("%d",&x);
		double p=(1.0*sqrt(5.0)+3.0)/2;
		long long ans=x*p;
		printf("%lld\n",ans);
	}
	return 0;
}