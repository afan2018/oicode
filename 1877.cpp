#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll f[40][100000]={0},dig[250]={0},a,b,test,wa=0,n;
ll Calc(int idx)
{
	int ret=1;
	for(int i=1;i<idx;i++)
		ret*=2;
	return ret;
}
ll DFS(ll pos,ll sum,bool hi)
{	
	if(pos==0) return sum<=wa;
	if(!hi&&f[pos][sum]!=-1) return f[pos][sum];
	ll ret=0,tmax=hi?dig[pos]:9;
	for(int i=0;i<=tmax;i++)
	{
		int ns=sum;
		ns+=i*Calc(pos);
		if(ns>wa) continue;
		ret+=DFS(pos-1,ns,(i==tmax)&&hi);
	}
	if(!hi) f[pos][sum]=ret;
	return ret;
}
ll Initb(ll x)
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
ll Inita(ll a)
{
	dig[0]=0;
	wa=0;
	while(a)
	{
		dig[++dig[0]]=a%10;
		a/=10;
	}
	for(int i=1;i<=dig[0];i++)
		wa+=dig[i]*Calc(i);
	return wa;
}
int main()
{
	cin>>test;
	int t=test;
	while(test--)
	{
		cin>>a>>b;
		n=Inita(a);
		cout<<"Case #"<<t-test<<": "<<Initb(b)<<endl;
		//cout<<n<<endl;
	}
	return 0;
}