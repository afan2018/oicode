#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,gcd,seq[105]={0};
long long lcm;
inline int Euclid(int a,int b)
{return b==0?a:Euclid(b,a%b);}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&seq[i]);
	gcd=seq[1];
	lcm=seq[1];
	for(int i=2;i<=n;i++)
	{
		gcd=Euclid(gcd,seq[i]);
		lcm=(lcm/Euclid(lcm,seq[i]))*seq[i];
	}
	printf("%d\n%lld",gcd,lcm);
	return 0;
}

