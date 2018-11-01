#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,m,ans=0;
inline int gcd(int a,int b)
{return b==0?a:gcd(b,a%b);}
int main()
{
	scanf("%d%d",&n,&m);
	if(m%n) {printf("0");return 0;}
	if(m==n) {printf("1");return 0;}
	m/=n;
	for(int i=1;i<=sqrt(m);i++)
	{
		if(m%i==0)
		{
			int j=m/i;
			if(gcd(i,j)==1) ans+=2;
		}
	}
	printf("%d",ans);
	return 0;
}
