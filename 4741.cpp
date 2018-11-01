#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll f[100005][20]={0},sum[100005]={0},n,unh[100005]={0};
void ST()
{
	for(ll i=1;i<=(ll)log2(n);i++)
		for(ll j=1;j+(1<<i)-1<=n;j++)
		{
			f[j][i]=f[j][i-1];
			if(unh[f[j][i-1]]>unh[f[j+(1<<(i-1))][i-1]]) f[j][i]=f[j+(1<<(i-1))][i-1];
		}
}
ll RMQ(ll l,ll r)
{
	ll idx=log2(r-l+1);
	if(unh[f[l][idx]]<unh[f[r-(1<<idx)+1][idx]]) return f[l][idx];
	return f[r-(1<<idx)+1][idx];
}
ll BS(ll l,ll r)
{
	
	if(l>r) return -1;
	if(l==r) return unh[l]*unh[l];
	ll pos=RMQ(l,r),here=unh[pos]*(sum[r]-sum[l-1]);
	return max(here,max(BS(l,pos-1),BS(pos+1,r)));
}
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++) 
	{
		cin>>unh[i];
		sum[i]=sum[i-1]+unh[i];
		f[i][0]=i;
	}
	ST();
	cout<<BS(1,n);
	return 0;
}