#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int l=1,r=0;
stack<int> stac;
string str;
int main()
{
	stac.push(-1);
	cin>>str;
	str=str+'(';
	for(int i=0;i<str.length();i++)
	{
		if(i-stac.top()-2>r-l) l=stac.top()+1,r=i-1;
		if(str[i]=='('||str[i]=='[') stac.push(i);
		if(str[i]==')')
		{
			if(!stac.empty()&&str[stac.top()]=='(') stac.pop();
			else {while(!stac.empty()) stac.pop();stac.push(i);}
		}
		if(str[i]==']')
		{
			if(!stac.empty()&&str[stac.top()]=='[') stac.pop();
			else {while(!stac.empty()) stac.pop();stac.push(i);}
		}
	}
	for(int i=l;i<=r;i++)
		cout<<str[i];
	return 0;
}
