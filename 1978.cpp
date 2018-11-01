#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int g,a[805];}f[10005],Catalan[10005];
void Print(node a)
{
	printf("%d",a.a[a.g]);
	for(int i=a.g-1;i>0;i--) printf("%04d",a.a[i]);
	if(a.g==0) printf("0");
	printf("\n");
}
node operator *(const node &a,const node &b)
{
	node c;memset(c.a,0,sizeof(c.a));
	for(int i=1;i<=a.g;i++)
		for(int j=1;j<=b.g;j++)
			c.a[i+j-1]+=a.a[i]*b.a[j],c.a[i+j]+=c.a[i+j-1]/10000,c.a[i+j-1]%=10000;
	c.g=a.g+b.g;
	while(c.a[c.g]==0) c.g--;
	return c;
}
node operator +(const node &a,const node &b)
{
	node c;memset(c.a,0,sizeof(c.a));
	c.g=max(a.g,b.g);
	for(int i=1;i<=c.g;i++) c.a[i]=a.a[i]+b.a[i];
	for(int i=1;i<=c.g;i++) c.a[i+1]+=c.a[i]/10000,c.a[i]%=10000;
	if(c.a[c.g+1]) c.g++;
	return c; 
}
node operator -(const node &a,const node &b)
{
	node c;memset(c.a,0,sizeof(c.a));
	c.g=max(a.g,b.g);
	for(int i=1;i<=c.g;i++) c.a[i]=a.a[i]-b.a[i];
	for(int i=1;i<=c.g;i++) if(c.a[i]<0) c.a[i+1]--,c.a[i]+=10000;
	while(c.a[c.g]==0) c.g--;
	return c; 
}
node operator +(const node &a,int x)
{
	node c=a;
	c.a[1]+=x;
	for(int i=1;i<=c.g;i++) c.a[i+1]+=c.a[i]/10000,c.a[i]%=10000;
	if(c.a[c.g+1]) c.g++;
	return c;
}
node operator -(const node &a,int x)
{
	node c=a;
	c.a[1]-=x;
	for(int i=1;i<c.g;i++) if(c.a[i]<0) c.a[i]+=10000,c.a[i+1]--;
	if(c.a[c.g]==0) c.g--;
	return c;
}
node operator /(const node &a,int x)
{
	node c=a;
	for(int i=c.g;i>0;i--)
		c.a[i-1]+=(c.a[i]%x)*10000,c.a[i]/=x;
	while(c.a[c.g]==0) c.g--; 
	return c;
}
node operator *(const node &a,int x)
{
	node c=a;
	for(int i=1;i<=c.g;i++) c.a[i]*=x;
	for(int i=1;i<=c.g;i++) c.a[i+1]+=c.a[i]/10000,c.a[i]%=10000;
	if(c.a[c.g+1]) c.g++;
	return c;
}
int main()
{
//	freopen("mushroom.in","r",stdin);
//	freopen("mushroom.out","w",stdout);
	int n;
	cin>>n;
	f[1].g=f[1].a[1]=1;
	int cnt=0;
	Catalan[0].g=Catalan[0].a[1]=1;
	Catalan[1].g=Catalan[1].a[1]=1;
	for(int i=2;i<=n;i++)
		Catalan[i]=Catalan[i-1]*(4*i-2)/(i+1);
	for(int i=2;i<=n;i++)
	{
		f[i]=f[i-1]*2;
		if(i%2==1)
			f[i]=f[i]-Catalan[++cnt];
	}
	Print(f[n]);
	return 0;
}