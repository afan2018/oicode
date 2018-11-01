#include<iostream>
using namespace std;
const int INF=1<<30;
int map[1005][1005]={0},dis[1005]={0},n,minn=INF,pla;
void Init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>map[i][j];
			if(!map[i][j]&&i!=j)map[i][j]=INF;
		}
}
void Floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(map[i][k]<INF&&map[k][j]<INF&&map[i][j]>map[i][k]+map[k][j])
					map[i][j]=map[i][k]+map[k][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i]+=map[i][j];
	for(int i=1;i<=n;i++)if(dis[i]<minn)minn=dis[i],pla=i;
	cout<<pla<<' '<<minn;
}
int main(){
	Init();
	Floyd();
	return 0;
}
/*
3
0 3 1
3 0 2
1 2 0
*/