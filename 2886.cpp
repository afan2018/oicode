#include<iostream>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int n,map[1005][1005]= {0},dis[1005]= {0},pla=0,minn=0,a,b,c;
void Init()
{
	cin>>n;
	memset(map,INF,sizeof(map));
	while(cin>>a>>b>>c) map[a][b]=map[b][a]=c;
}
void Floyd()
{
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(map[i][k]<INF&&map[k][j]<INF&&map[i][j]>map[i][k]+map[k][j])
					map[i][j]=map[i][k]+map[k][j];
}
void Center()
{
	int maxx=-INF;
	for(int i=1; i<=n; i++)
	{
		maxx=-INF;
		for(int j=1; j<=n; j++)
			if(i!=j&&map[i][j]>maxx) maxx=map[i][j];
		dis[i]=maxx;
	}
	minn=INF;
	for(int i=1; i<=n; i++)if(dis[i]<minn)minn=dis[i],pla=i;
	cout<<pla<<endl;;
}
int main()
{
	Init();
	Floyd();
	Center();
	return 0;
}
/*
4
1 2 3
2 3 2
3 4 5
*/