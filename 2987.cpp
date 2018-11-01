#include<iostream>
using namespace std;
const int INF=1<<30;
int n=0,m=0,map[105][105]={0};
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			map[i][j]=INF;
	for(int i=1;i<=n;i++) map[i][i]=0;
	int a,b,c;
	for(int i=1;i<=m;i++)
		cin>>a>>b>>c,map[a][b]=c,map[b][a]=c;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(map[i][k]!=INF&&map[k][i]!=INF&&map[i][j]>map[i][k]+map[k][j])
					map[i][j]=map[i][k]+map[k][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<map[i][j]<<' ';
		cout<<endl;
	}
		
	return 0;
}
