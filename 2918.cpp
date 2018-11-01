#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
long long num,sum=0,len=0,idx=1,p[2005]={0};
string str;
int main()
{
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	cin>>str>>num;
	str=' '+str;
	len=str.length()-1;
	for(int i=1;i<=len;i++)
	{
		sum*=26;
		sum+=str[i]-'A';
		sum%=num;
	}
	if(sum==0) {cout<<"0 0";return 0;}
	p[1]=1;
	for(int i=2;i<=len;i++)
		p[i]=(p[i-1]*26)%num;
	for(int i=1;i<len;i++)
		for(int j=i;j<=len;j++)
		{
			int hh=sum-p[len-i+1]*(str[i]-'A')-p[len-j+1]*(str[j]-'A')+p[len-i+1]*(str[j]-'A')+p[len-j+1]*(str[i]-'A');
			if(hh%num==0) {cout<<i<<' '<<j;return 0;}
		}
	cout<<"-1 -1";
	return 0;
}