#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
string str,s,key;
char buffer[1005];
int strl,klen;
int main()
{
	scanf("%s",buffer);
	key=buffer;
	klen=key.length();
	key=' '+key;
	scanf("%s",buffer);
	str=buffer;
	strl=str.length();
	str=' '+str;
	int ps=1,pk=1;
	while(1)
	{
		int big=0;
		if(ps>strl) break;
		if(pk>klen) pk=1;
		char chk=key[pk],chs=str[ps];
		int foo=0;
		if(chk>='A'&&chk<='Z') foo=chk-'A';
		else foo=chk-'a';
		if(chs<='z'&&chs>='a')
		{
			if(chs-foo<'a') printf("%c",char('z'-(foo-(chs-'a')-1)));
			else printf("%c",char(chs-foo));
		}
		else
		{
			if(chs-foo<'A') printf("%c",char('Z'-(foo-(chs-'A')-1)));
			else printf("%c",char(chs-foo));
		}
		ps++;
		pk++;
	}
	return 0;
}