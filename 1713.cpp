#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
int w[1005]={0},n,maxw,f[100005]={0},fa[100005]={0},used[1005]={0};
using namespace std;
int main()
{
	cin>>maxw>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	f[0]=1;
	if(maxw==0) 
	{
		for(int i=1;i<=n;i++)
			cout<<i<<' ';
		return 0;
	}	
	for(int i=1;i<=n;i++)
		for(int j=maxw;j>=w[i];j--)
		{
			if(f[j-w[i]]) 
			{
				if(f[j]==0) f[j]=1,fa[j]=i;
				else f[j]=-1;
 			}
 			else if(f[j-w[i]]==-1) f[j]=-1;
		}
	if(f[maxw]==0||f[maxw]==-1)
		{cout<<f[maxw];return 0;}
	int res=maxw;
	while(res!=0)
	{
		used[fa[res]]=1;
		res-=w[fa[res]];
	}
	for(int i=1;i<=n;i++)
		if(!used[i]) cout<<i<<' ';
	return 0;
}