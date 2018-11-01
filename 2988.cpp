#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
struct node{int fr,to,val;}edge[100005];
int n,m,ans=0,cnt=0,fa[1005]={0};
inline bool cmp(const node &a,const node &b)
{return a.val<b.val;}
inline int Getfa(int x)
{return x==fa[x]?fa[x]:fa[x]=Getfa(fa[x]);}
void K()
{
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int fa1=Getfa(edge[i].fr);
		int fa2=Getfa(edge[i].to);
		if(fa1!=fa2)
		{
			fa[fa1]=fa2;
			cnt++;
			ans=max(ans,edge[i].val);
			if(cnt==n-1) break;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&edge[i].fr,&edge[i].to,&edge[i].val);
	sort(edge+1,edge+m+1,cmp);
	K();
	(cnt<n-1)?puts("-1"):printf("%d",ans);
	return 0;
}
