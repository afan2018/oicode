#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int a[105],b[105],c[105],hh;
string str;
void Read(int hhh[])
{
	cin>>str;
	hhh[0]=str.length();
	for(int i=1;i<=hhh[0];i++)
		hhh[i]=str[hhh[0]-i]-'0';
}
bool cmp(int a[],int b[])
{
	if(a[0]>b[0]) return 1;
	if(a[0]<b[0]) return -1;
	for(int i=a[0];i>=1;i--)
	{
		if(a[i]>b[i]) return 1;
		if(a[i]<b[i]) return -1;
	}
	return 0;
}
void HPlus()
{
	if(a[0]<b[0]) a[0]=b[0];
	for(int i=1;i<=a[0];i++)
		a[i]+=b[i];
	for(int i=1;i<=a[0];i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	if(a[a[0]+1]) a[0]++;
}
void HMinus()
{
	int fl=cmp(a,b);
	if(fl==0) {a[0]=0;return;}
	if(fl==1)
	{
		for(int i=1;i<=a[0];i++)
		{
			if(a[i]<b[i]) a[i+1]--,a[i]+=10;
			a[i]-=b[i];
		}
		while(a[0]>0&&a[a[0]]==0) {a[0]--;}
		return;
	}
	if(fl==-1)
	{
		cout<<'-';
		for(int i=1;i<=b[0];i++)
		{
			if(b[i]<a[i]) b[i+1]--,b[i]+=10;
			a[i]=b[i]-a[i];
		}
		a[0]=b[0];
		while(a[0]>0&&a[a[0]]==0) {a[0]--;}
		return;
	}	
}
void HMul()
{
	c[0]=0;
	for(int i=1;i<=a[0];i++)
		for(int j=1;i<=b[0];j++)
			c[i+j-1]=a[i]*b[i];
	c[0]=a[0]+b[0];
	for(int i=1;i<=c[i];i++)
	{
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	while(c[0]>0&&c[c[0]]==0) {c[0]--;}
	return;
}
void HDiv()
{
	int d=0;
	for(int i=a[0];i>=1;i--)
	{
		d=d*10+a[i];
		a[i]=d/hh;
		d%=hh;
	}
	while(a[0]>0&&a[a[0]]==0) {a[0]--;}
	return;
}
void Print()
{
	if(a[0]==0) {cout<<0;return;}
	for(int i=a[0];i>=1;i--)
		cout<<a[i];
}
int main()
{
	Read(a);
	Read(b);
	HPlus();
	Print();
	return 0;
}