#include<iostream>
using namespace std;
int scc=0,bel[1005]={0},hhh=0,top=0,low[1005]={0},dfn[1005]={0},n,map[1005][1005]={0},stack[1005]={0},ins[1005]={0},cnt,ans,into[1005]={0};
void Init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>map[i][j];
}
void Tarjan(int x)
{
	dfn[x]=low[x]=++cnt;
	stack[++top]=x;
	ins[x]=1;
	for(int i=1;i<=n;i++)
		if(map[x][i])
		{
			if(!dfn[i])
			{
				Tarjan(i);
				low[x]=min(low[x],low[i]);
			}
			else if(ins[i]) low[x]=min(low[x],dfn[i]);
		}	
	if(dfn[x]==low[x])
	{
		scc++;
		do hhh=stack[top--],ins[hhh]=0,bel[hhh]=scc;
		while(hhh!=x);
	}
}
void Solve()
{
	for(int i=1;i<=n;i++)if(!dfn[i])Tarjan(i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(map[i][j]&&bel[i]!=bel[j])into[bel[j]]++;
	for(int i=1;i<=scc;i++)
		if(!into[i])ans++;
	cout<<ans<<endl;
}
int	main(){
	Init();
	Solve();
	return 0;
}
/*
8
0 0 1 0 0 0 0 0 
1 0 0 1 0 0 0 0 
0 1 0 1 1 0 0 0 
0 0 0 0 0 1 0 0 
0 0 0 1 0 0 0 0 
0 0 0 1 0 0 0 0 
0 0 0 1 0 0 0 1
0 0 0 0 0 0 1 0
*/