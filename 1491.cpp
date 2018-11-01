#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
int T;
ll unit[5][5],f[5][5],L,R;
void Mul(ll a[][5],ll b[][5])
{
	ll ret[5][5]={0};
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++)
				ret[i][j]=(ret[i][j]+a[i][k]*b[k][j])%10000;
	memcpy(a,ret,sizeof(ret));
}
ll Get(ll pos)
{
	if(pos==0) return 0;
	if(pos==1) return 1;
	memset(unit,0,sizeof(unit));
	memset(f,0,sizeof(f));
	f[1][1]=f[1][3]=f[2][1]=f[1][2]=f[2][3]=f[3][3]=1;
	for(int i=1;i<=3;i++) unit[1][i]=1;
	unit[1][3]++;
	pos-=2;
	while(pos>0)
	{
		if(pos&1) Mul(unit,f);
		Mul(f,f);
		pos/=2;
	}
	return unit[1][3]%10000;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&L,&R);
		printf("%lld\n",(Get(R)-Get(L-1)+10000)%10000);
	}
	return 0;
}