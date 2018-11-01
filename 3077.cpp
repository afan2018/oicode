#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct node{int to,nx;}edge[100005];
struct Node{int a,b;}ans[100005],foo[100005];
int h[100005]={0},ccnt=0,cnt=0,n,num[100005],fa[100005]={0},root,pre;
bool cmp1(const Node &a,const Node &b)
{return a.b<b.b||(a.b==b.b&&a.a>b.a);}
bool cmp2(const Node &a,const Node &b)
{return a.b>b.b||(a.b==b.b&&a.a<b.a);}
void Add(int x,int y)
{edge[++ccnt].to=y,edge[ccnt].nx=h[x],h[x]=ccnt;}
void DFS(int x,int sta)
{
	int cnt=0;
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		DFS(to,3-sta);
	}
	for(int i=h[x];i;i=edge[i].nx) foo[++cnt]=ans[edge[i].to];
	if(sta==1) //alice
	{
		if(cnt==0) ans[x].a=max(ans[x].a,num[x]);
		else
		{
			sort(foo+1,foo+cnt+1,cmp2);
			ans[x].a=foo[1].a+num[x];
			ans[x].b=foo[1].b;
		}
	}
	else //bob
	{
		if(cnt==0) ans[x].b=max(ans[x].b,num[x]);
		else
		{
			sort(foo+1,foo+cnt+1,cmp1);
			ans[x].b=foo[1].b+num[x];
			ans[x].a=foo[1].a;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",num+i);
	for(int i=1,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		fa[y]=x;
		Add(x,y);
	}
	root=1;
	while(fa[root]) root=fa[root];
	DFS(root,1);
	printf("%d %d\n",ans[root].a,ans[root].b);
	return 0;
}
