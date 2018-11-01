#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const ll MOD (1000000000);
char buffer[305];
string str;
ll f[305][305]={0},n;
int main()
{
	scanf("%s",buffer);
	str=buffer;
	n=str.length();
	for(ll i=0;i<n;i++) f[i][i]=1;
	for(ll i=1;i<=n;i++)
	{
		if(i&1==0) continue;
		for(ll L=0;L+i<n;L++)
		{
			ll R=L+i;
			if(str[L]==str[R])
			{
				f[L][R]=f[L+1][R-1];
				for(ll j=L+2;j<R;j++)
					if(str[L]==str[j])
						f[L][R]=(f[L][R]+f[L+1][j-1]*f[j][R]%MOD)%MOD;
			}
		}
	}
	printf("%lld",f[0][n-1]);
	return 0;
}
