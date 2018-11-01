#include<iostream>
using namespace std;
int n,num[10]={0},lim[10]={0},t[26]={0},hash[26]={0},cnt=0;
string s1;
void array(int tr)
{
	if(tr==n+1)
	{
		cout<<++cnt<<":";
		for(int i=1;i<=n;i++)cout<<char(t[num[i]]+'a');
		cout<<endl; 
		return;
	}
	else for(int i=1;i<=n;i++)
	{
		if(lim[i]){
			num[tr]=i;
			lim[i]--;
			array(tr+1);
			lim[i]++; 
		}
	}
}
int main(){
	cin>>s1;
	n=s1.length();
	for(int i=0;i<n;i++)hash[s1[i]-'a']++;
	int p=0;
	for(int i=0;i<26;i++)
	  	if(hash[i]>0)t[++p]=i,lim[p]=hash[i];
	array(1);
	return 0;
}