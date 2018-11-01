#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll x,y,k,b,dig[105]={0},f[105][105][105]={0};
ll DFS(int pos,int la,int c0,int c1,bool hi)
{
	if(pos==0) return c0>=c1;
	if(!hi&&f[pos][c0][c1]!=-1) return f[pos][c0][c1];
	ll ret=0,tmax=hi?dig[pos]:1;
	for(int i=0;i<=tmax;i++)
	{
		if(i==0) ret+=DFS(pos-1,la,c0+(la?0:1),c1,hi&&(i==tmax));
		else ret+=DFS(pos-1,0,c0,c1+1,hi&&(i==tmax));
	}
	if(!hi) f[pos][c0][c1]=ret;
	return ret;
}
ll Init(ll a)
{
	memset(f,-1,sizeof(f));
	dig[0]=0;
	while(a)
	{
		dig[++dig[0]]=a%2;
		a/=2;
	}
	return DFS(dig[0],1,0,0,1);
}
int main()
{
	cin>>x>>y;
	cout<<Init(y)-Init(x-1);
	return 0;
}