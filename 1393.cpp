#include<iostream>
#include<cstring>
using namespace std;
int h[15005]={0},dfn[15005]={0},cnt,n,m,sign=0,ans=0,prt[15005]={0},lowlink[15005]={0};
struct node{int next,to;}edge[80005];
void AddEdge(int x,int y)
{edge[++cnt].to=y,edge[cnt].next=h[x],h[x]=cnt;}
void Init()
{
	int a,b;
	memset(h,0,sizeof(h));
	memset(dfn,0,sizeof(dfn));
	memset(prt,0,sizeof(prt));
	memset(edge,0,sizeof(edge));
	memset(lowlink,0,sizeof(lowlink));
	cnt=ans=sign=0;
	for(int i=1;i<=m;i++) cin>>a>>b,AddEdge(a,b),AddEdge(b,a);
}
void DFS(int x)
{
	lowlink[x]=dfn[x]=++sign;
	for(int i=h[x];i;i=edge[i].next)
	{
		int too=edge[i].to;
		if(prt[x]!=too)
		{
			if(!dfn[too])
			{
				prt[too]=x;
				DFS(too);
				lowlink[x]=min(lowlink[x],lowlink[too]);
				if(lowlink[too]>dfn[x]) ans++;
			}
			else lowlink[x]=min(lowlink[x],dfn[too]);
		}
	}
}
int main()
{
	while(cin>>n>>m)
	{
		if(n+m==0)break;
		Init();
		DFS(1);
		cout<<ans<<endl;
	}
	return 0;
}
