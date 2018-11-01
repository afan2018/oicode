#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char buffer[200005],s[400005];
string str;
int len=0,P[400005]={0},ans=0,map[400005]={0},pos=0,slen=0,blen=0;
void Manacher()
{
	int id=1;
	P[1]=1;
	for(int i=2;i<=len;i++)
	{
		if(id+P[id]>i) P[i]=min(P[2*id-i],id+P[id]-i);
		else P[i]=1;
		while(i>P[i]&&s[i+P[i]]==s[i-P[i]]) P[i]++;
		if(i+P[i]>id+P[id]) id=i;
		if(P[i]>ans) ans=P[i],pos=i;
	}
}
int main()
{
	while(~scanf("%c",&buffer[blen])) blen++;
	s[0]='$';
	str=buffer;
	slen=str.length();
	str=' '+str;
	for(int i=1;i<=slen;i++)
	{
		char ch=str[i];
		if((ch<'a'||ch>'z')&&(ch<'A'||ch>'Z')) continue;
		if(ch>='A'&&ch<='Z')
		{
			ch-='A';
			ch+='a';
		}
		s[++len]='#';
		s[++len]=ch;
		map[len]=i;
	}
	s[++len]='#';
	Manacher();
	int L=map[pos-(ans-1)+1],R=map[pos+(ans-1)-1];
	printf("%d\n",ans-1);
	for(int i=L;i<=R;i++)
		printf("%c",str[i]);
	return 0;
}