#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll f[25][15][15][3][3][3]={0},dig[25]={0},a,b;
bool Judge(ll f2,ll f1,ll now)
{
	return (f2==f1&&f1==now);
}
ll DFS(ll pos,ll f2,ll f1,bool ei,bool fo,bool cyc,bool hi)
{	
	if(pos==0) return cyc;
	if(!hi&&f[pos][f2][f1][ei][fo][cyc]!=-1) return f[pos][f2][f1][ei][fo][cyc];
	ll ret=0,tmax=hi?dig[pos]:9;
	for(int i=(pos==dig[0]);i<=tmax;i++)
	{
		if((fo&&i==8)||(ei&&i==4)) continue;
		ret+=DFS(pos-1,f1,i,ei||(i==8),fo||(i==4),cyc||Judge(f2,f1,i),(i==tmax)&&hi);
	}
	if(!hi) f[pos][f2][f1][ei][fo][cyc]=ret;
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
	return DFS(dig[0],0,0,0,0,0,1);
}
int main()
{
	cin>>a>>b;
	if(a==10000000000) cout<<Init(b);
	else cout<<Init(b)-Init(a-1);
	return 0;
}
