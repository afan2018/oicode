#include<iostream>
using namespace std;
long long sum=0;
int cost[10005]={0},need[10005]={0},n,s;
int main()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)
		cin>>cost[i]>>need[i];
	for(int i=2;i<=n;i++)
		cost[i]=min(cost[i],cost[i-1]+s);
	for(int i=1;i<=n;i++)
		sum+=cost[i]*need[i];
	cout<<sum;
	return 0;
}
