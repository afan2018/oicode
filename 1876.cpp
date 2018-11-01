#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll f[40][12][2]={0},dig[250]={0},a,test;
ll DFS(ll pos,ll f1,bool bj,bool hi)
{	
	if(pos==0) return bj;
	if(!hi&&f[pos][f1][bj]!=-1) return f[pos][f1][bj];
	ll ret=0,tmax=hi?dig[pos]:9;
	for(int i=0;i<=tmax;i++)
	{
		
		ret+=DFS(pos-1,i,bj||(f1==4&&i==9),(i==tmax)&&hi);
	}
	if(!hi) f[pos][f1][bj]=ret;
	return ret;
}
ll Init(ll x)
{
	memset(f,-1,sizeof(f));
	dig[0]=0;
	while(x)
	{
		dig[++dig[0]]=x%10;
		x/=10;
	}
	return DFS(dig[0],0,0,1);
}
int main()
{
	cin>>test;
	while(test--)
	{
		scanf("%lld",&a);
		printf("%lld\n",Init(a));
	}
	return 0;
}