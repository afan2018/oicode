#include<iostream>
using namespace std;
int into[5005]={0},ans=0,cnt=0,sign=0,top=0,stack[5005]={0},h[5005]={0},n,m,bcc=0,bel[5005]={0},low[5005]={0},dfn[5005]={0};
struct node{int to,nx,opp,vst;}edge[20005];
void Addedge(int x,int y)
{
	edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt,edge[cnt].opp=cnt+1,edge[cnt].vst=0;
	edge[++cnt].to=x,edge[cnt].nx=h[y],h[y]=cnt,edge[cnt].opp=cnt-1,edge[cnt].vst=0;
}
void Init()
{
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=m;i++)
		cin>>a>>b,Addedge(a,b);
}
void Tarjan(int x)
{
	int tooo;
	dfn[x]=low[x]=++sign;
	stack[++top]=x;
	for(int i=h[x];i;i=edge[i].nx)
		if(!edge[edge[i].opp].vst)
		{
			edge[i].vst=1;
			int too=edge[i].to;
			if(!dfn[too])
			{
				Tarjan(too);
				low[x]=min(low[x],low[too]);
			}
			else low[x]=min(low[x],dfn[too]);
		}
		else edge[i].vst=1;
	if(low[x]==dfn[x])
	{
		bcc++;
		do tooo=stack[top--],bel[tooo]=bcc;
		while(tooo!=x);
	}
}
void Print()
{
	int tooo=0;
	for(int i=1;i<=n;i++)
		for(int j=h[i];j;j=edge[j].nx)
			if(edge[edge[j].opp].vst)
			{
				edge[j].vst=0;
				tooo=edge[j].to;
				if(bel[i]!=bel[tooo])
					into[bel[i]]++,into[bel[tooo]]++;
			}
			else edge[j].vst=0;
	for(int i=1;i<=bcc;i++)
		if(into[i]==1)ans++;
	cout<<(ans+1)/2<<endl;
}
int main(){
	Init();
	Tarjan(1);
	Print();
	return 0;
}
