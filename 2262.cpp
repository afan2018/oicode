#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
string car[10005],str[10005];
int n,m;
struct node{int g,a[1005];}f[10005];
void Print(node a)
{
	printf("%d",a.a[a.g]);
	for(int i=a.g-1;i>0;i--) printf("%04d",a.a[i]);
	if(a.g==0) printf("0");
	printf("\n");
}
node operator +(const node &a,const node &b)
{
	node c;
	memset(c.a,0,sizeof(c.a));
	c.g=max(a.g,b.g);
	for(int i=1;i<=c.g;i++) c.a[i]=a.a[i]+b.a[i];
	for(int i=1;i<=c.g;i++) c.a[i+1]+=c.a[i]/10000,c.a[i]%=10000;
	if(c.a[c.g+1]) c.g++;
	return c;
}
void Init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		char buffer[260];
		scanf("%s",buffer);
		car[i]=buffer;
	}
	for(int i=1;i<=m;i++)
	{
		char buffer[260];
		scanf("%s",buffer);
		str[i]=buffer;
	}
}
void QueryA()
{
	sort(car+1,car+n+1);
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int l=1,r=n,mid;
		while(l<r)
		{
			mid=(l+r)/2;
			if(str[i]<car[mid]) r=mid;
			else l=mid+1;
		}
		if(str[i]==car[l].substr(0,str[i].length())) cnt++;
	}
	printf("%d\n",cnt);
}
void QueryB()
{
	f[1].g=1,f[1].a[1]=1;
	f[2].g=1,f[2].a[1]=2;
	for(int i=3;i<=n;i++)
		f[i]=f[i-1]+f[i-2];
	Print(f[n]);
}
int main()
{
	Init();
	QueryA();
	QueryB();
	return 0;
}
