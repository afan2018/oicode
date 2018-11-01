#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{int la,ra,ls,rs;} bal[105]={0}; 
int n,rt=1,fa[105]={0};
long long DFS(int x)
{
	if(x==0) return 1;
	long long l=DFS(bal[x].ls),r=DFS(bal[x].rs),idx=__gcd(l*(bal[x].la),r*(bal[x].ra));
	return l*(r*bal[x].ra)/idx+r*(l*bal[x].la)/idx;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>bal[i].la>>bal[i].ra>>bal[i].ls>>bal[i].rs;
		if(bal[i].ls) fa[bal[i].ls]=i;
		if(bal[i].rs) fa[bal[i].rs]=i;
	}
	while(fa[rt]) rt=fa[rt];
	cout<<DFS(rt);
	return 0;
}
