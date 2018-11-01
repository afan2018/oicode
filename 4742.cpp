#include<iostream>
using namespace std;
typedef long long ll;
ll C[10005][5005]={0},n,a[1000005]={0},b[1000005]={0},maxa=0,maxb=0,ans=1;
#define YH\
{\
	for(int i=1;i<=maxb;i++) C[0][i]=1;\
	for(int i=1;i<=maxa;i++)\
		for(int j=1;j<=maxb;j++)\
			C[i][j]=(C[i-1][j]+C[i][j-1])%1000007;\
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		maxa=max(a[i],maxa);
		maxb=max(b[i],maxb);
	}
	YH;
	for(int i=1;i<=n;i++)
		ans=(ans*C[a[i]][b[i]])%1000007;
	cout<<ans;
	return 0;
}