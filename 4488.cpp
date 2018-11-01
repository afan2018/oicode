#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
struct Matrix
{
	ll mat[5][5];
	Matrix(){memset(mat,0,sizeof(mat));}
}Unit,a;
ll K,N,P,ans=0,cnt=1;
Matrix operator *(const Matrix a,const Matrix b)
{
	Matrix ret;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			for(int k=1;k<=2;k++)
				ret.mat[i][j]=((ret.mat[i][j]+a.mat[i][k]*b.mat[k][j]%P)+P)%P;
	return ret;
}
int main()
{
	scanf("%lld%lld%lld",&K,&N,&P);
	N-=2;
	for(int i=1;i<=2;i++) Unit.mat[i][i]=1;
	a.mat[1][1]=1,a.mat[1][2]=0;
	a.mat[2][1]=K,a.mat[2][2]=K;
	while(N)
	{
		if(N&1) Unit=Unit*a;
		a=a*a;
		N/=2;
	}
	ans=((Unit.mat[1][1]%P+Unit.mat[2][1]%P)+P)%P;
	printf("%lld",ans);
	return 0;
}
