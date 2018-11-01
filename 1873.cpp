#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll f[505][505]={0},dig[250]={0},a,b,n;
ll DFS(ll pos,ll res,bool hi)
{	
	if(pos==0) return res==0;
	if(!hi&&f[pos][res]!=-1) return f[pos][res];
	ll ret=0,tmax=hi?dig[pos]:9;
	for(int i=0;i<=tmax;i++)
		ret+=DFS(pos-1,(i+res)%n,(i==tmax)&&hi);	
	if(!hi) f[pos][res]=ret;
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
	while(cin>>a>>b>>n)
		cout<<Init(b)-Init(a-1)<<endl;
	return 0;
}