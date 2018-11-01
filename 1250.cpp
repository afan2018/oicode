#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{int fr,to,val;}edge[30005]={0};
int fa[30005]={0},n,m;
int Get(int x)
{return x==fa[x]?x:fa[x]=Get(fa[x]);}
void K()
{
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int fa1=Get(edge[i].fr);
		int fa2=Get(edge[i].to);
		if(fa1!=fa2)
		{
			fa[fa1]=fa2;
			cnt++;
			ans+=edge[i].val;
		}
		if(cnt==n-1) break;
	}
	cout<<ans;
}
inline bool cmp(node a,node b)
{return a.val<b.val;}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>edge[i].fr>>edge[i].to>>edge[i].val;
	sort(edge+1,edge+m+1,cmp);
	K();
	return 0;
}