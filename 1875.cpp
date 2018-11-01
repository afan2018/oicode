#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll f[15][3][15]={0},dig[15]={0},a;
ll DFS(int pos,bool sta,bool hi,int res)
{
	if(pos==0) return res%13==0;
	if(!hi&&f[pos][sta][res]!=-1) return f[pos][sta][res];
	int ret=0,to=hi?dig[pos]:9;
	for(int i=0;i<=to;i++)
	{
		if(sta&&i==3) continue; 
		ret+=DFS(pos-1,i==1,hi&&i==to,(res*10+i)%13);
	}
	if(!hi) f[pos][sta][res]=ret; 
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
	return DFS(pos,0,1,0);
}
int main(){
	memset(f,-1,sizeof(f));
	while(cin>>a&&a!=EOF)
		cout<<a/13-Init(a)+1<<endl;
	return 0;
}