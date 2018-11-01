#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
string str;
int len;
int LowOper(int l,int r)
{
	int cnt=0,fl=0,pos=r;
	for(int i=l;i<=r;i++)
	  {if(str[i]=='(') cnt++;
		if(str[i]==')') cnt--;
		if(cnt==0&&str[i]=='+') return i;
		
		if(str[i]=='*'&&cnt==0) pos=min(pos,i); 
	}
	return pos;
}
int TrBla(int l,int r)
{
	int cnt=0;
	for(int i=l;i<=r;i++)
	{
		if(str[i]=='(') cnt++;
		if(str[i]==')')
			if(--cnt==0) return i;
	}
}
int Calc(int a,int pos,int b)
{
	a%=10000,b%=10000;
	if(str[pos]=='+') return (a+b)%10000;
	if(str[pos]=='*') return (a*b)%10000;
}
int Find(int l,int r)
{
	int sum=0,cnt=1;
	for(int i=r;i>=l;i--)
	{
		if(str[i]<'0'||str[i]>'9')
			return -1;
		sum+=(str[i]-'0')*cnt,cnt*=10;
	}
	return sum;
}
int Get(int l,int r)
{
	int ret=Find(l,r);
	if(ret!=-1) return ret;
	if(str[l]=='('&&TrBla(l,r)==r) return Get(l+1,r-1);
	int pos=LowOper(l,r);
	int numl=Get(l,pos-1);
	int numr=Get(pos+1,r);
	return Calc(numl,pos,numr);
}
int main()
{
	cin>>str;
	len=str.length();
	str=' '+str;
	int l,r;
	cout<<Get(1,len)%10000;
	return 0;
}
/*
(1+2*3+(5*6)*100)
*/