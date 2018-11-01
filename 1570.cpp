#include<iostream>
using namespace std;
int n,k[233330]={0};
void cheng(int s[],int a)
{
	for(int i=233329;i>=1;i--)
		if(s[i]!=0) {s[0]=i;break;}
	for(int i=1;i<=s[0];i++)
		s[i]*=a;
	for(int i=1;i<=s[0];i++)
	{
		s[i+1]+=s[i]/10;
		s[i]%=10;
	}
	while(s[s[0]+1]>0)
	{
		s[0]++;
		s[s[0]+1]=s[s[0]]/10;
		s[s[0]]%=10;
	}
}
int main()
{
	volatile int i;
	cin>>n;
	k[1]=1;
	//k[0]=1;
	for(i=1;i<=n;i++)
		cheng(k,i);
	if(k[0]==0) {cout<<0;return 0;}
	for(i=k[0];i>=1;i--)
		cout<<k[i];
	return 0;
}
