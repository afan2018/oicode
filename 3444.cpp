#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
struct Matrix
{
	ll mat[35][35];
	Matrix(){memset(mat,0,sizeof(mat));}
}a,nine,ans,sum,unit;
ll n,k;
Matrix operator *(const Matrix &a,const Matrix &b)
{
	Matrix c;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int kk=1;kk<=n;kk++)
				c.mat[i][j]=(c.mat[i][j]+a.mat[i][kk]*b.mat[kk][j]%2012)%2012;
	return c;
}
Matrix operator +(const Matrix &a,const Matrix &b)
{
	Matrix c;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			c.mat[i][j]=(a.mat[i][j]+b.mat[i][j])%2012;
	return c;
}
Matrix Power(Matrix x,int idx)
{
	Matrix Unit;
	for(int i=1;i<=n;i++)
		Unit.mat[i][i]=1;
	while(idx)
	{
		if(idx&1) Unit=Unit*x;
		x=x*x;
		idx/=2;
	}
	return Unit;
}
Matrix Get(int x)
{
	if(x==1) return a;
	if(x&1)
	{
		Matrix foo=Get(x/2);
		Matrix bar=Power(a,x/2);
		return ((foo+foo*bar)+Power(a,x));
	}
	Matrix foo=Get(x/2);
	Matrix bar=Power(a,x/2);
	return (foo+foo*bar);
}
int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%lld",&a.mat[i][j]);
	nine=a;
	for(int i=1;i<9;i++)
		nine=nine*a;
	sum=Get(k);
	ans=sum*nine;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%lld ",ans.mat[i][j]);
		printf("\n");
	}
	return 0;
}
