#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,sum=0,f[90005]={0},g[90005]={0},ans[100005]={0};
struct node{int c,v,t;} a[100500];
int Getint()
{
	int bj=1,ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') bj=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {ret=ret*10+ch-'0';ch=getchar();}
	return ret;
}
bool cmp(const node &a,const node &b)
{return a.t<b.t||(a.t==b.t&&a.v>b.v);}
int main()
{
	n=Getint();
	m=Getint();
	for(int i=1;i<=n;i++)
	{
		a[i].c=Getint();
		a[i].v=Getint();
		a[i].t=Getint();
	}
	for(int i=1;i<=m;i++)
	{
		a[n+i].t=Getint();
		a[n+i].c=Getint();
		a[n+i].v=-i;
	}
	sort(a+1,a+n+m+1,cmp);
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	f[0]=g[0]=0;
	for(int i=1;i<=n+m;i++)
	{
		if(a[i].v<0)
		{
			int L=0,R=sum,mid,Ans=-1;
			while(L<=R)
			{
				mid=(L+R)/2;
				if(g[mid]<=a[i].c) Ans=mid,L=mid+1;
				else R=mid-1;
			}
			ans[-a[i].v]=Ans;
			continue;
		}
		sum+=a[i].v;
		for(int j=sum;j>=a[i].v;j--) f[j]=min(f[j],f[j-a[i].v]+a[i].c);
		for(int j=sum;j>=1;j--) g[j]=min(g[j+1],f[j]);
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}