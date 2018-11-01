#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll x,y,k,b,dig[105]={0},f[105][105]={0};
ll DFS(int pos,int par,bool hi)
{
	if(par>k) return 0ll;
	if(pos==0) return par==k;
	if(!hi&&f[pos][par]!=-1) return f[pos][par];
	ll ret=0,tmax=hi?min(1ll,dig[pos]):1;
	for(int i=0;i<=tmax;i++)
		ret+=DFS(pos-1,par+i,hi&&(i==dig[pos]));
	if(!hi) f[pos][par]=ret;
	return ret;
}
ll Init(ll a)
{
	memset(f,-1,sizeof(f));
	dig[0]=0;
	while(a)
	{
		dig[++dig[0]]=a%b;
		a/=b;
	}
	return DFS(dig[0],0,1);
}
int main()
{
	cin>>x>>y>>k>>b;
	cout<<Init(y)-Init(x-1);
	return 0;
}