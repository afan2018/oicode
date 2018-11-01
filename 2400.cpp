#include<iostream>
using namespace std;
int ccnt=0,n,m,k,l,cnt=0,ans=0;;
int h[100005]={0},sera[100005]={0},serb[100005]={0},dfn[100005]={0},low[100005]={0},prt[100005]={0};
struct node {int to,next;} edge[1000005];
void AddEdge(int x,int y)
{edge[++cnt].to=y,edge[cnt].next=h[x],h[x]=cnt;};
void Init()
{
	int num,a,b;
	cin>>n>>m>>k>>l;
	for(int i=1;i<=k;i++)
		cin>>num,sera[num]=1;
	for(int i=1;i<=l;i++)
		cin>>num,serb[num]=1;
	for(int i=1;i<=m;i++)
		cin>>a>>b,AddEdge(a,b),AddEdge(b,a);
}
void DFS(int x)
{
	int too;
	dfn[x]=low[x]=++ccnt;
	for(int i=h[x];i;i=edge[i].next)
	{
		too=edge[i].to;
		if(prt[x]!=too)
		{
			if(!dfn[too])
			{
				prt[too]=x;
				DFS(too);
				low[x]=min(low[x],low[too]);
				sera[x]+=sera[too];
				serb[x]+=serb[too];
				if(low[too]>dfn[x]&&(!sera[too]||!serb[too]||sera[too]==k||serb[too]==l))
					ans++;
			}
			else low[x]=min(low[x],dfn[too]);
		}
	}
}
int main(){
	Init();
	DFS(1);
	cout<<ans<<'\n';
	return 0;
}