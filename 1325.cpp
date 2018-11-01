#include<iostream>
#include<cstring>
#include<cstdio>
const int INF=105;
using namespace std;
int map[105][105]={0},dfn[105]={0},lowlink[105]={0},prt[105]={0};
int n,cnt=0,ans=INF,son=0,bj[105]={0},sta=0,end=0;
void Init()
{
	int x,y;
	cin>>n;
	while(cin>>x>>y){if(!(x+y))break;map[x][y]=map[y][x]=1;}
	cin>>sta>>end;
}
void DFS(int x)
{
	lowlink[x]=dfn[x]=++cnt;
	for(int i=1;i<=n;i++)
		if(map[x][i]&&prt[x]!=i)
		{
			if(!dfn[i])
			{
				prt[i]=x;
				DFS(i);
				lowlink[x]=min(lowlink[x],lowlink[i]);
			}
			else lowlink[x]=min(lowlink[x],dfn[i]);
		}
}
void Check(int x)
{
	if(x==sta)return;
	if(lowlink[x]>=dfn[prt[x]]&&prt[x]!=sta&&prt[x]<ans)ans=prt[x];
	Check(prt[x]);
}
int main(){
	Init();
	DFS(sta);
	Check(end);
	if(ans==INF) cout<<"No solution";
	else cout<<ans<<endl;
	return 0;
}