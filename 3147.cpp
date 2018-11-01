#include<cstdio>
typedef long long ll;
const ll MOD=10007;
ll C[1005][1005]={0},a,b,k,n,m,ans=1;
#define YH\
{\
	C[0][0]=1;\
	for(int i=1;i<=k;i++)\
	{\
		C[i][0]=C[i][i]=1;\
		for(int j=1;j<i;j++)\
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;\
	}\
}
int main()
{
	scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
	a%=MOD;
	b%=MOD;
	YH;
	ll foo=1,bar=1;
	for(int i=1;i<=n;i++) foo=(foo*a)%MOD;;
	for(int i=1;i<=m;i++) bar=(bar*b)%MOD;
	ans=((C[k][m]*foo)%MOD*bar)%MOD;
	printf("%lld",ans);
	return 0;
}