#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;
typedef long long ll;
ll n,A[50005]={0},B[50005]={0},f[50005]={0},pos,sum[50005]={0};
ll ansa=0,ansb=0;
ll Squ(ll x)
{return x*x;}
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",A+i);
	for(ll i=1;i<=n;i++) scanf("%lld",B+i);
	sort(A+1,A+n+1);
	sort(B+1,B+n+1);
	for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+B[i];
	pos=0;
	for(ll i=1;i<=n;i++)
	{
		f[i]=f[i-1]+pos*(Squ(A[i])-Squ(A[i-1]))+2*sum[pos]*(A[i-1]-A[i]);
		while(pos<n&&A[i]>=B[pos+1])
		{
			pos++;
			f[i]+=Squ(A[i]-B[pos]);
		}
		ansa+=f[i];
	}
	pos=0;
	memset(f,0,sizeof(f));
	for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+A[i];
	for(ll i=1;i<=n;i++)
	{
		f[i]=f[i-1]+pos*(Squ(B[i])-Squ(B[i-1]))+2*sum[pos]*(B[i-1]-B[i]);
		while(pos<n&&B[i]>=A[pos+1])
		{
			pos++;
			f[i]+=Squ(B[i]-A[pos]);
		}
		ansb+=f[i];
	}
	cout<<fixed<<setprecision(1)<<(long double)(((long double)(ansa-ansb)/n));
	return 0;
}
/*
2
3 7
1 5
*/