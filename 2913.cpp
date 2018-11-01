#include <iostream>
using namespace std;
string str;
long long t,len;
int main()
{
	cin>>str>>t;
	len=str.length();
	str=' '+str;
	int x=0,y=0,ptr=0;
	for(int i=1;i<=len;i++)
	{
		if(str[i]=='N') y++;
		else if(str[i]=='E') x++;
		else if(str[i]=='S') y--;
		else x--;
	}
	int hh=t/len,pos=t%len;
	x*=hh,y*=hh;
	for(int i=1;i<=pos;i++)
	{
		if(str[i]=='N') y++;
		else if(str[i]=='E') x++;
		else if(str[i]=='S') y--;
		else x--;
	}
	cout<<x<<' '<<y;
}