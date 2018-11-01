#include<cstdio>
inline int Getint()
{	int ret=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
	return ret;
}
int main()
{
	int n,now,last=0,ans=0;
	n=Getint();
	for(int i=1;i<=n;i++)
	{
		now=Getint();
		if(now>last) ans+=now-last;
		last=now;
	}
	printf("%d",ans);
	return 0;
}