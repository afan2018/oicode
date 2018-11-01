#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,divi[50000]={0},ans[210]={0},cnt=0,sum=0;
inline int Getint()
{
	int bj(1),ret(0);
	char ch=getchar();
	while(ch>'9'||ch<'0') {if(ch=='-') bj=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {ret=ret*10+ch-'0';ch=getchar();}
	return ret;
}
int main()
{
	n=Getint();
	m=Getint();
	for(int i=1,x;i<=m;i++)
	{
		x=Getint();
		for(int i=1;i*i<=x;i++)
			if(x%i==0)
			{
				divi[++cnt]=i;
				if(x/i!=i) divi[++cnt]=x/i;
			}
	}
	divi[++cnt]=1e9+1;
	sort(divi+1,divi+cnt+1);
	int foo=0;
	for(int i=1;i<cnt;i++)
	{
		if(divi[i]>=n) break;
		if(divi[i]==divi[i+1]) foo++;
		if(divi[i]!=divi[i+1]) ans[++foo]++,foo=0;
	}
	for(int i=1;i<=m;i++) sum+=ans[i];
	printf("%d\n",n-sum);
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}
