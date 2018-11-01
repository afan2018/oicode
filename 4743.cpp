#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
string str,mod;
int nx[10000005]={0},modl=0,strl=0,ga,gb,del=0,pos=0;
char scanner[10000005];
void Getnx()
{
	int ptr=0;
	nx[1]=0;
	for(int i=2;i<=modl;i++)
	{
		while(ptr>0&&mod[ptr+1]!=mod[i]) ptr=nx[ptr];
		if(mod[ptr+1]==mod[i]) ptr++;
		nx[i]=ptr;
	}
}
void KMP()
{
	int ptr=0;
	nx[1]=0;
	for(int i=1;i<=strl;i++)
	{
		while(ptr>0&&mod[ptr+1]!=str[i]) ptr=nx[ptr];
		if(mod[ptr+1]==str[i]) ptr++;
		if(ptr==modl) {pos=i-modl+1;return;}
	}
}
int main()
{
	scanf("%s",scanner);
	str=scanner;
	ga=str.length();
	str=' '+str+str;
	strl=str.length()-1;
	scanf("%s",scanner);
	mod=scanner;
	gb=mod.length();
	mod=' '+mod;
	modl=mod.length()-1;
	del=ga-gb;
	Getnx();
	KMP();
	for(int i=pos+modl;i<=pos+modl+del-1;i++)
		cout<<str[i];
	return 0;
}