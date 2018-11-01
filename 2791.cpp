#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll can[1000005]={0},c[1000005]={0},ave,n,sum=0;
ll afan(ll a)
{return a>0?a:-a;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>can[i],sum+=can[i];
	ave=sum/n;
	for(int i=1;i<=n;i++)
		c[i]=c[i-1]+can[i]-ave;
	sort(c+1,c+n+1);
	ll x1=c[(n+1)/2],ans=0;
	for(int i=1;i<=n;i++)
		ans+=afan(x1-c[i]);
	cout<<ans;
	return 0;
}
