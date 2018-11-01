#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll f[15][3]={0},dig[15]={0},a,b;
ll DFS(int pos,bool sta,bool hi)
{
	if(pos==0) return 1;
	if(!hi&&f[pos][sta]!=-1) return f[pos][sta];
	int ret=0,to=hi?dig[pos]:9;
	for(int i=0;i<=to;i++)
	{
		if(i==4||(i==2&&sta)) continue;
		ret+=DFS(pos-1,i==6,hi&&i==to);
	}
	if(!hi) f[pos][sta]=ret; 
	return ret;
}
ll Init(ll n)
{
	int pos=0;
	while(n)
	{
		dig[++pos]=n%10;
		n/=10;
	}
	return DFS(pos,0,1);
}
int main(){
	memset(f,-1,sizeof(f));
	while(cin>>a>>b&&(a||b))
	{
		cout<<Init(b)-Init(a-1)<<endl;
	}
	return 0;
}
