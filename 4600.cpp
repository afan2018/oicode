#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll f[25][15][15][3][3][3]={0},dig[25]={0},a,b;
bool Judge(int f2,int f1,int now)
{
	return ((f2-1==f1)&&(f1-1==now))||((f2+1==f1)&&(f1+1==now));
}
ll DFS(ll pos,ll f2,ll f1,bool to,bool fo,bool cyc,bool hi)
{	
	if(pos==0) return cyc;
	if(!hi&&~f[pos][f2][f1][to][fo][cyc]) return f[pos][f2][f1][to][fo][cyc];
	ll ret=0,tmax=hi?dig[pos]:9;
	for(int i=0;i<=tmax;i++)
	{
		if((to&&i==4)||(fo&&i==2)) continue;
		ret+=DFS(pos-1,f1,(f1==12&&i==0)?12:i,to||(i==2),fo||(i==4),cyc||Judge(f2,f1,i),(i==tmax)&&hi);
	}
	if(!hi) f[pos][f2][f1][to][fo][cyc]=ret;
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
	return DFS(dig[0],12,12,0,0,0,1);
}
int main()
{
	cin>>a>>b;
	cout<<Init(b)-Init(a-1);
	return 0;
}
