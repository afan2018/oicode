#include<iostream>
#include<cstring>
const int INF=0x7fffffff/3;
using namespace std;
int map[305][305]= {0},n,m,ans=INF,dis[305][305];
void Init()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)if(i!=j)map[i][j]=INF;
	int a,b,c;
	for(int i=1; i<=m; i++)
	{
		cin>>a>>b>>c;
		map[a][b]=map[b][a]=c;
	}
}
void Floyd()
{
	memcpy(dis,map,sizeof(map));
	for(int k=1; k<=n; k++)
	{
		for(int i=1; i<k; i++)
			for(int j=i+1; j<k; j++)
				ans=min(ans,dis[i][j]+map[i][k]+map[k][j]);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(dis[i][k]!=INF&&dis[k][j]!=INF)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	if(ans==INF)cout<<"No solution.";
	else cout<<ans;
}
int main()
{
	Init();
	Floyd();
	return 0;
}
/*
5 6
1 4 1
3 1 10
1 2 16
2 3 100
2 5 15
5 3 20
*/