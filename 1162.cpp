#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string a;
	char b[1000],c[1000];
    b[0]='A';c[0]='A';
	cin>>a;
	int len=a.length();
	for(int i=1;i<=len/2;i++)
	   b[i]=a[i-1];
	if(len%2==0)
	   for(int i=len/2;i>=1;i--)
	     c[i]=a[len/2+i-1];//1657561//145541//1441 131  12321
    else
      for(int i=len/2;i>=1;i--)
	     c[i]=a[len/2+i];
	for(int i=1;i<=len/2/2;i++)
		swap(c[i],c[len/2-i+1]);
	if(!strncmp(b,c,len/2+1))cout<<"YES\n";
	  else cout<<"NO\n";
	return 0;
}
