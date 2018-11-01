#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll f[505][505]={0},dig[250]={0},a,b;
ll DFS(ll pos,ll f1,bool hi)
{	
	if(pos==0) return 1;
	if(!hi&&f[pos][f1+10]!=-1) return f[pos][f1+10];
	ll ret=0,tmax=hi?dig[pos]:9;
	for(int i=0;i<=tmax;i++)
	{
		if(i<f1)continue;
		int afansb=(f1==-8&&i==0)?-8:i;
		ret+=DFS(pos-1,afansb,(i==tmax)&&hi);
		}	
	if(!hi) f[pos][f1+10]=ret;
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
	return DFS(dig[0],-8,1);
}
int main()
{
	while(cin>>a>>b)
		cout<<Init(b)-Init(a-1)<<endl;
	return 0;
}