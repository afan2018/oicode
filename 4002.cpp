#include<cstdio>
typedef long long ll;
const ll MOD=3;
ll T,n,m,C[5][5]={0};
inline ll Lucas(ll n,ll m)
{return m==0?1:C[n%MOD][m%MOD]*Lucas(n/MOD,m/MOD)%MOD;}
int main()
{
	C[0][0]=1;
	C[1][0]=1;
	C[1][1]=1;
	C[2][0]=1;
	C[2][1]=2;
	C[2][2]=1;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		printf("%lld\n",(((m&1)?-1:1)*Lucas(2*n,m)%MOD+MOD)%MOD);
	}
	return 0;
}