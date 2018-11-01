#include<cstdio>
int a,b,c,foo,bar;
inline int gcd(int a,int b)
{return b==0?a:gcd(b,a%b);}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	if(!c) {printf("0");return 0;}
	foo=(b-a)*(b-a)-(b-a-c)*(b-a-c);
	bar=gcd(foo,(b-a)*(b-a));
	printf("%d/%d",foo/bar,(b-a)*(b-a)/bar);
	return 0;
}
