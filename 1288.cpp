#include<iostream>
using namespace std;
string s;
char a[23333];
int len=0;
void shan()
{
	int i,j;
	char D;
	cin>>D;
	for(i=1;i<=len;i++)
		if(a[i]==D)
		{
			for(j=i;j<=len-1;j++)
				a[j]=a[j+1];
			len--;
			return;
		}
//	for(int i=1;i<=len;i++)
//		cout<<a[i];
//	cout<<endl;
}
void cha()
{
	char r,R;//R为要插的
	cin>>r>>R;
	int i,j;
	for(i=len;i>=1;i--)
	{
		if(a[i]==r)
		{
			for(j=len;j>=i;j--)
				a[j+1]=a[j];
			len++;
			a[i]=R;
			return;
		}
	}
//	for(int i=1;i<=len;i++)
//		cout<<a[i];
//	cout<<endl;
}
void huan()
{
	char r,R;
	cin>>r>>R;
	int i;
	for(i=1;i<=len;i++)
		if(a[i]==r)a[i]=R;
//	for(int i=1;i<=len;i++)
//		cout<<a[i];
//	cout<<endl;
}
int main()
{
	int i,n;
	char ch;
	getline(cin,s);
	cin>>n;
	len=s.length();
	for(i=1;i<=len;i++)
	{
		if(s[i-1]=='.')
		{
			len=i;
			a[i]=s[i-1];
			break;
		}
		a[i]=s[i-1];
	}

	for(i=1;i<=n;i++)
	{
		cin>>ch;
		if(ch=='D')
			shan();
		else if(ch=='I')
			cha();
		else if(ch=='R')
			huan();
	}
	for(i=1;i<=len;i++)
		cout<<a[i];
	return 0;
}
