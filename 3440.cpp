#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct node{int fr,to;}ask[100005],add[300005];
int n,m,Q,fa[100005]={0},fl[300005]={0},ans[100005]={0};
int Getfa(int x)
{return fa[x]==x?x:fa[x]=Getfa(fa[x]);}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&add[i].fr,&add[i].to);
	scanf("%d",&Q);
	for(int i=1,x;i<=Q;i++)
	{
		scanf("%d",&x);
		if(x) scanf("%d%d",&ask[i].fr,&ask[i].to);
		else
		{
			scanf("%d",&ask[i].fr);
			fl[ask[i].fr]=1;
			ask[i].to=-1;
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(fl[i]) continue;
		int fa1=Getfa(add[i].fr),fa2=Getfa(add[i].to);
		fa[fa1]=fa2;
	}
	for(int i=Q;i>=1;i--)
	{
		if(ask[i].to==-1)
		{
			int fa1=Getfa(add[ask[i].fr].fr),fa2=Getfa(add[ask[i].fr].to);
			fa[fa1]=fa2;
			continue;
		}
		int fa1=Getfa(ask[i].fr),fa2=Getfa(ask[i].to);
		ans[i]=(fa1==fa2);
	}
	for(int i=1;i<=Q;i++)
		if(ask[i].to!=-1) ans[i]?puts("Yes"):puts("NO");
	return 0;
}
