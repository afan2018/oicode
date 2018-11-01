#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll f[15][1<<15]={0},w,h,tot=0;
bool Come(ll x)
{
	ll cnt=0;
	while(x)
	{
		if(x&1) cnt++;
		else if(cnt&1) return false;
		x>>=1; 
	}
	if(cnt&1) return false;
	return true;
}
bool Check(ll a,ll b)
{
	for(ll i=1;i<tot;)
	{
		if(((a&i)==0)&&((b&i)==0)) return false;
		if((a&i)&&(b&i))
		{
			if((a&(i<<1))&&(b&(i<<1))) {i<<=2;continue;}
			return false;
		}
		i<<=1;
	}
	return true;
}
void DP()
{
	tot=1<<h;
	memset(f,0,sizeof(f));
	for(ll i=0;i<tot;i++) if(Come(i)) f[1][i]=1;
	
	for(ll i=2;i<=w;i++)
		for(ll j=0;j<tot;j++)
			for(ll k=0;k<tot;k++)
				if(Check(j,k))f[i][j]+=f[i-1][k];
}
int main()
{
	while(cin>>w>>h)
	{
		if((w*h)&1) {cout<<"0"<<'\n';continue;}
		if(w<h) swap(w,h);
		DP();
		cout<<f[w][tot-1]<<'\n';
	}
	return 0;
}
