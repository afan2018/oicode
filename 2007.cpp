#include<iostream>
#include<cstdio>
using namespace std;
int getint()
{
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	int ret=0;
	while(c>='0'&&c<='9')
	{
		ret=ret*10+c-'0';
	    c=getchar();
	}
	return ret;
}
void putint(int ret)
{
	if(ret/10)putint(ret/10);
	putchar('0'+ret%10);
	return;
}
int a[30];
void cheng(int n)
{
	for(int i=1;i<=a[0];i++)
	a[i]=a[i]*n;
	for(int i=1;i<=a[0];i++)
	{
		a[i+1]+=a[i]/10000;
		a[i]=a[i]%10000;
	}
	while(a[a[0]+1])
	{
		a[0]++;
		a[a[0]+1]=a[a[0]]/10000;
		a[a[0]]%=10000;
	}
	return;
}
void sc()
{
	putint(a[a[0]]);
	for(int i=a[0]-1;i>0;i--)
	{
		putint(a[i]/1000);
		putint(a[i]/100%10);
		putint(a[i]/10%10);
		putint(a[i]%10);
	}
	return;
}
int n;
void Hanoi_Double()
{
     a[0]=1;a[1]=1;
     for(int i=1;i<=n+1;i++)cheng(2);
     a[1]-=2;
     return;
}
int main(){
	n=getint();
	Hanoi_Double();
	sc();
	return 0;
}