#include<iostream>
#define lovelive long long
using namespace std;
int main(){
	lovelive map[105][105]={0},n,m,tra[105][105]={0},path[105][105]={0},gd=0,gr=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			char ch;
			cin>>ch;
			map[i][j]=ch-'0';
		}
	path[0][1]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int nx=0;
			if(tra[i-1][j]==tra[i][j-1])nx=tra[i-1][j],gr=1,gd=1;
			else if(tra[i-1][j]>tra[i][j-1])nx=tra[i-1][j],gd=1,gr=0;
			else nx=tra[i][j-1],gr=1,gd=0;
			
			tra[i][j]=map[i][j]+nx;
			path[i][j]=path[i-1][j]*gd+path[i][j-1]*gr;
		}
	cout<<tra[n][m]<<endl<<path[n][m];
	return 0;
}
