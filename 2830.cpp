#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,unit[5][5],f[5][5],A,B;
void Mul(ll a[][5],ll b[][5])
{
	ll ret[5][5]={0};
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			for(int k=1;k<=2;k++)
				ret[i][j]=(ret[i][j]+a[i][k]*b[k][j])%7;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			a[i][j]=ret[i][j];
}
int main()
{
	scanf("%lld%lld%lld",&A,&B,&n);
	memset(unit,0,sizeof(unit));
	memset(f,0,sizeof(f));
	f[1][1]=A;
	f[1][2]=1;
	f[2][1]=B;
	f[2][2]=0;
	for(int i=1;i<=2;i++) unit[1][i]=1;
	n-=2;
	while(n>0)
	{
		if(n&1) Mul(unit,f);
		Mul(f,f);
		n/=2;
	}
	printf("%lld\n",unit[1][1]%7);
	return 0;
}