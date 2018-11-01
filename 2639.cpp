#include<iostream>
#include<cstdio>
using namespace std;
int n,a,b,c,d,i,e,ans,z,r;
char s;
inline int gcd(long long x,long long y)
{
	if(x%y==0) return y;
	return gcd(y,x%y);
}
inline int Getint()
{
	r=0;
	s=getchar();
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9')
	{
		r=r*10+s-'0';
		s=getchar();
	}
	return r;
}
int main()
{
	n=Getint();
	while(n--)
	{
		ans=0;
		a=Getint();
		b=Getint();
		c=Getint();
		d=Getint();
		e=d/c;
		z=gcd(e,c);
		while(z>1)
		{
			e*=z;
			c/=z;
			z=gcd(e,c);
		}
		for(i=1;i*i<=c;i++)
		{
			if(c%i==0)
			{
				if(b==gcd(a,e*i)) ans++;
				if(i*i!=c&&b==gcd(a,e*(c/i))) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
