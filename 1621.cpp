#include<iostream>
using namespace std;
int len=0,f[5005][5005],ans=9999999;;
string str;
int main(){
	cin>>len>>str;
	str=' '+str;
	for(int i=1;i<=len;i++)f[0][i]=len-i+1,f[i][len+1]=i;
	for(int i=1;i<=len;i++)
		for(int j=len;j>=1;j--)
		{
			if(str[i]==str[j]) f[i][j]=f[i-1][j+1];
			else f[i][j]=min(f[i-1][j],f[i][j+1])+1;
		}
	for(int i=0;i<=len;i++)
	{
		if(f[i][i+1]<ans) ans=f[i][i+1];
		if(i>0&&f[i][i]<ans) ans=f[i][i];
	}
	cout<<ans;
	return 0;
}
