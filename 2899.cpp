#include<iostream>
#include<cstring>
const int INF=0x3f3f3f3f;
using namespace std;
int map[105][105]={0},path[105][105]={0};
int n,m,a,b,c,s,t;
void Init()
{
	cin>>n>>m;
	memset(map,INF,sizeof(map));
	for(int i=1;i<=m;i++)
		cin>>a>>b>>c,map[a][b]=map[b][a]=min(map[a][b],c);
	cin>>s>>t;
}
void Floyd()
{	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(map[i][j])path[i][j]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{	
				if(map[i][j]==map[i][k]+map[k][j])
					path[i][j]+=path[i][k]*path[k][j];
				else if(map[i][k]<INF&&map[k][j]<INF&&map[i][j]>map[i][k]+map[k][j])
					{
						map[i][j]=map[i][k]+map[k][j];
						path[i][j]=path[i][k]*path[k][j];
					}
			}
	if(!path[s][t])cout<<"poor ty";
	else cout<<path[s][t];
}
int main(){
	Init();
	Floyd();
	return 0;
}
/*
3 3
1 2 1
2 3 2
1 3 3
1 3
*/