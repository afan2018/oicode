#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int fa[100005]={0},n,m;
int Getfa(int x)
{
	if(fa[x]==x) return x;
	fa[x]=Getfa(fa[x]);
	return fa[x];
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,a,b,fl,faa,fab;i<=m;i++)
	{
		cin>>a>>b>>fl;
		faa=Getfa(a),fab=Getfa(b);
		if(fl&&faa==fab) {cout<<"No";return 0;}
		if(!fl&&faa!=fab) fa[faa]=fab;
	}
	cout<<"Yes";
	return 0;
}
