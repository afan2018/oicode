#include<cstdio>
long long ans=0;
int cnta[5005]={0},cntb[5005]={0},n,m,p,q,A,B,C,D,E,F,a1,a2,b1,b2;
int main()
{
	scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d",&p,&q,&n,&a1,&a2,&A,&B,&C,&m,&b1,&b2,&D,&E,&F);
	A%=p,B%=p,C%=p;
	a1%=p,a2%=p;
	cnta[a1]++,cnta[a2]++;
	for(int i=3;i<=n;i++)
	{
		int foo=((A*a2-B*a1-C)%p+p)%p;
		cnta[foo]++;
		a1=a2,a2=foo;
	}
	D%=(p-1),E%=(p-1),F%=(p-1);
	b1%=(p-1),b2%=(p-1);
	cntb[b1]++,cntb[b2]++;
	for(int i=3;i<=m;i++)
	{
		int foo=(D*b2+E*b1+F)%(p-1);
		cntb[foo]++;
		b1=b2,b2=foo;
	}
	ans=(long long)cnta[0]*m;
	for(int i=1;i<p;i++)
	{
		if(cnta[i]==0) continue;
		int foo=1;
		for(int j=0;j<p-1;j++)
		{
			if(foo<=q) ans+=(long long)cnta[i]*cntb[j];
			foo=foo*i%p;
		}
	}
	printf("%lld",ans);
	return 0;
}