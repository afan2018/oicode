#include<iostream>
using namespace std;
string str1,str2;
int len1=0,len2=0,f[3005][3005]={0};
int main()
{
	cin>>str1>>str2;
	len1=str1.length(),len2=str2.length();
	str1=' '+str1,str2=' '+str2;
	for(int i=1;i<=len1;i++)
		for(int j=1;j<=len2;j++)
		{
			if(str1[i]==str2[j]) f[i][j]=f[i-1][j-1]+1;
			else f[i][j]=max(f[i-1][j],f[i][j-1]);
		}
	cout<<f[len1][len2];
	return 0;
}
