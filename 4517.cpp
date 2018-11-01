#include<iostream>
using namespace std;
int x,y,seq[40][40]={0},n,cnt=1;//x hang y lie
int main(){
	cin>>n;
	seq[1][n/2+1]=1;
	x=1,y=n/2+1;
	while(cnt<=n*n)
	{
		if(x==1&&y!=n)seq[x=n][++y]=++cnt;
		if(x!=1&&y==n)seq[--x][y=1]=++cnt;
		if(x!=1&&y!=n&&!seq[x-1][y+1])seq[--x][++y]=++cnt;
		if(x!=1&&y!=n&&seq[x-1][y+1])seq[++x][y]=++cnt;
		if(x==1&&y==n)seq[++x][y]=++cnt;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<seq[i][j]<<' ';
		cout<<endl;	
	}
	return 0;
}
