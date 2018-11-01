#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll f[40][12]={0},dig[250]={0},a,b;
ll DFS(ll pos,ll f1,bool hi)
{	
	if(pos==0) return 1;
	if(!hi&&f[pos][f1]!=-1) return f[pos][f1];
	ll ret=0,tmax=hi?dig[pos]:9;
	for(int i=0;i<=tmax;i++)
	{
		if((i==4)||((f1==3)&&i==7)) continue;
		ret+=DFS(pos-1,i,(i==tmax)&&hi);
	}
	if(!hi) f[pos][f1]=ret;
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
	return DFS(dig[0],0,1);
}
int main()
{
	cin>>a>>b;
	cout<<Init(b)-Init(a-1);
	return 0;
}