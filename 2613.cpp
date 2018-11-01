#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n;
string hh;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>hh;
		if((hh[hh.length()-1]-'0')%2==1) cout<<"odd\n";
		else cout<<"even\n";
	}
	return 0;
}
