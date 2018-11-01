#include<iostream>
using namespace std;
int T,n,a[105],b[105];
inline int gcd(int a,int b)
{return b==0?a:gcd(b,a%b);}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int fl=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",a+i,b+i);
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if((b[i]-b[j])%gcd(a[i],a[j])) fl=0;
				if(!fl) break;
			}
		if(fl) puts("possible");
		else puts("impossible");
	}
	return 0;
}
