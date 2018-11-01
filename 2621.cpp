#include<iostream>
#include<cstring>
const int INF=0x3f3f3f3f;
using namespace std;
int vis[2505]={0},dis[2505]={0},map[2505][2505]={0},ts=0,te=0,n,m;
void D(int sou)
{
	int k,minn;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) dis[i]=INF;
	dis[sou]=0;
	for(int i=1;i<=n;i++)
	{
		minn=INF;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&minn>dis[j]) minn=dis[j],k=j;
		vis[k]=1;
		for(int j=1;j<=n;j++)
			if(map[k][j]<INF&&!vis[j]&&dis[k]+map[k][j]<dis[j])
				dis[j]=dis[k]+map[k][j];
	}
}
int main()
{
	cin>>n>>m>>ts>>te;
	memset(map,INF,sizeof(map));
	for(int i=1,a,b,c;i<=m;i++)
		cin>>a>>b>>c,map[a][b]=map[b][a]=c;
	D(ts);
	cout<<dis[te];
	return 0;
}
