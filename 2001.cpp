#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
string str,afan;
int p1,p2,p3,len,dis,jump=0,fl1,fl2,hh=0;
int C(int pos)
{
	fl1=0,fl2=0;
	if(str[pos-1]==str[pos+1]) return 1;//xiangdeng
	if(str[pos-1]>='0'&&str[pos-1]<='9') fl1=1;//shuzi
	if(str[pos-1]>='a'&&str[pos-1]<='z') fl1=2;//zimu
	if(str[pos+1]>='0'&&str[pos+1]<='9') fl2=1;
	if(str[pos+1]>='a'&&str[pos+1]<='z') fl2=2;
	if(fl1!=fl2) return 1;//butonglei
	if(fl1==1)
	{
		dis=(str[pos-1]-'0')-(str[pos+1]-'0');
		dis=-dis;
		if(dis<0) return 1;
	}
	if(fl1==2)
	{
		dis=(str[pos-1]-'a')-(str[pos+1]-'a');
		dis=-dis;
		if(dis<0) return 1;
	}
	return 0;
}
void Make(int pos)
{
	afan=str;
	dis=0;
	jump=0;
	if(C(pos)) return;
	if(dis==1) {jump=1;hh=1;return;}
	if(p1==3)
	{
		for(int i=1;i<=(dis-1)*p2;i++)
			cout<<'*';
		hh=1;
		return;
	}
	if(p1==1&&fl1==2)//xiaoxie
	{
		if(p3==2)//queren nixu
		{
			int fr=int(str[pos-1]);
			for(int i=dis-1;i>=1;i--)
				for(int j=1;j<=p2;j++)
					cout<<char(fr+i);
		}
		else
		{
			int fr=int(str[pos-1]);
			for(int i=1;i<dis;i++)
				for(int j=1;j<=p2;j++)
					cout<<char(fr+i);
		}
		hh=1;
		return;
	}
	if(p1==2&&fl1==2)//daxie
	{
		if(p3==2)//queren nixu
		{
			int fr=int(str[pos-1]-'a'+'A');
			for(int i=dis-1;i>=1;i--)
				for(int j=1;j<=p2;j++)
					cout<<char(fr+i);
		}
		else
		{
			int fr=int(str[pos-1]-'a'+'A');
			for(int i=1;i<dis;i++)
				for(int j=1;j<=p2;j++)
					cout<<char(fr+i);
		}
		hh=1;
		return;
	}
	if(fl1==1)//shuzi
	{
		if(p3==2)//nixu
		{
			int fr=int(str[pos-1]);
			for(int i=dis-1;i>=1;i--)
				for(int j=1;j<=p2;j++)
					cout<<char(fr+i);
		}
		else 
		{
			int fr=int(str[pos-1]);
			for(int i=1;i<dis;i++)
				for(int j=1;j<=p2;j++)
					cout<<char(fr+i);
		}
		hh=1;
		return;
	}
}
int main()
{
//	freopen("expand.in","r",stdin);
//	freopen("expand.out","w",stdout);
	cin>>p1>>p2>>p3>>str;
	len=str.length();
	str=' '+str;
	for(int i=1;i<=len;i++)
	{
		hh=0;
		if(str[i]=='-') Make(i);//liang tou jian hao chu li
		if(jump==1) {jump=0;continue;}
		if(hh)
			if(str[i]=='-') continue;
		cout<<str[i];
	}
	return 0;
}