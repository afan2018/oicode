#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{int fr,to,val;}edge[20005];
int fa[2005]={0},n,m;
bool cmp(node a,node b)
{return a.val<b.val;}
int G(int x)
{return fa[x]==x?x:fa[x]=G(fa[x]);}
void K()
{
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int fa1=G(edge[i].fr);
		int fa2=G(edge[i].to);
		if(fa1!=fa2)
		{
			fa[fa1]=fa2;
			ans=max(ans,edge[i].val);
			cnt++;
		}
		if(cnt==n-1) break;
	}
	cout<<ans;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>edge[i].fr>>edge[i].to>>edge[i].val;
	sort(edge+1,edge+m+1,cmp);
	K();
	return 0;
}