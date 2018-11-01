#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{int hh,uh;}peo[1005]={0};
int n,ans=0,num=0;
bool cmp(const node &x,const node &y)
{return x.hh>y.hh;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>peo[i].hh,ans=max(ans,peo[i].hh);
	for(int i=1;i<=n;i++)
		cin>>peo[i].uh;
	for(int i=2;i<=n;i++)
	{
		int val=0;
		for(int j=1;j<=n;j++)
			peo[j].hh-=peo[j].uh;
		sort(peo+1,peo+n+1,cmp);
		for(int j=1;j<=i;j++)
			val+=peo[j].hh;
		if(val>=ans) {ans=val;num=i;}	
	}
	cout<<ans<<'\n'<<num;
	return 0;
}