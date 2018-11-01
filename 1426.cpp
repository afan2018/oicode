#include<iostream>
#include<algorithm>
using namespace std;
string str[10005];
int n,f[10005]={0};
bool judge(string a,string b)
{
	if(b.length()<a.length()) return false;
	for(int i=0;i<a.length();i++)
		if(a[i]!=b[i]) return false;
	return true;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>str[i],f[i]=1;
	for(int i=2;i<=n;i++)
		for(int j=i-1;j>=1;j--)
			if(judge(str[j],str[i])&&f[j]+1>f[i]){f[i]=f[j]+1;break;}
	int maxx=1;
	for(int i=1;i<=n;i++)
		maxx=max(f[i],maxx);
	cout<<maxx;
	return 0;
}
