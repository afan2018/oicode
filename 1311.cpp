#include<iostream>
#include<cstring>
const int INF=0x3f3f3f3f;
using namespace std;
int map[105][105]={0},n,m,a,b,c,maxx=0,rd[105]={0};
void Floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(map[i][k]!=0&&map[k][j]!=0&&map[i][j]<map[i][k]+map[k][j])
					map[i][j]=map[i][k]+map[k][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(map[i][j]>maxx)maxx=map[i][j];
	cout<<maxx;
}
int main(){
	cin>>n>>m;
	memset(map,0,sizeof(map));
	for(int i=1;i<=m;i++)cin>>a>>b>>c,map[a][b]=c;
	Floyd();
	return 0;
}
/*
5 5
1 2 2
2 4 9
1 3 7
3 4 1
4 5 6
*/