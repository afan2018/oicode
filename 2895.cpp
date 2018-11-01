#include<iostream>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,a,b,c,map[105][105]={0},dis[105]={0},maxx=0;
void Init()
{
	cin>>n>>m;
	memset(map,INF,sizeof(map));
	memset(dis,INF,sizeof(dis));
	for(int i=1;i<=m;i++)
		cin>>a>>b>>c,map[a][b]=map[b][a]=c;	
}
void Floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(map[i][k]<INF&&map[k][j]<INF&&map[i][j]>map[i][k]+map[k][j])
					map[i][j]=map[i][k]+map[k][j];
}
void Dia()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(map[i][j]>maxx&&i!=j)maxx=map[i][j];
	cout<<maxx;
}
int main(){
	Init();
	Floyd();
	Dia();
	return 0;
}