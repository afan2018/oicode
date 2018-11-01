#include<iostream>
using namespace std;
int n,num[10]={0},lim[10]={0},t[26]={0},hash[26]={0},tar,len=0;
string s1;
void array(int tr)
{
	if(tr==tar+1)
	{
		for(int i=1;i<=tar;i++)cout<<char(t[num[i]]+'a');
		cout<<endl;
		return;
	}
	else for(int i=1+len;i<=n;i++)
	{
		if(!lim[i]){
			num[tr]=i;
			lim[i]=1;
			len=i;
			array(tr+1);
			lim[i]=0; 
		} 
	}
}
int main(){
	cin>>s1>>tar;
	n=s1.length();
	for(int i=0;i<n;i++)hash[s1[i]-'a']++;
	int p=0;
	for(int i=0;i<26;i++)
	  if(hash[i]==1)t[++p]=i;
	array(1);
	return 0;
}