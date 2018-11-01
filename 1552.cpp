#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int len,sum=1;
	len=s.length();
	for(int i=0;i<len-1;i++)
	if((s[i]<'a'&&s[i]>'Z')||s[i]<'A'||s[i]>'z') sum++;
	cout<<sum;
	return 0;
}
