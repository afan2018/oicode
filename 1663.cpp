#include<iostream>
#include<cstring>
#include<algorithm>
const int INF=0x3f3f3f3f;
using namespace std;
int map[105][105]={0},n,m,a,b,c,ans=0,rd[105]={0},sta=0,cnt=0;
void Floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(map[i][k]!=0&&map[k][j]!=0&&map[i][j]<map[i][k]+map[k][j])
					map[i][j]=map[i][k]+map[k][j];
}
int main(){
	cin>>n>>m;
	n++;
	memset(map,0,sizeof(map));
//	for(int i=1;i<=n;i++)map[i][i]=0;
	for(int i=1;i<=m;i++)cin>>a>>b>>c,map[a][b]=max(map[a][b],c),rd[b]++;
	Floyd();
//	for(int i=1;i<=n;i++)cout<<rd[i]<<' ';
//	cout<<endl<<"_______________"<<endl;
//	cout<<map[1][n]<<"%%%%"<<endl;
	for(int i=1;i<=n;i++)
		if(!rd[i]&&ans<map[i][n])ans=map[i][n],sta=i;
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		if(map[sta][i]+map[i][n]==ans)cout<<i<<' ';
	return 0;
}
/*
4
5
1 2 2
2 3 2
3 5 3
1 4 3
4 5 3
*/