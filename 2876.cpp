#include<iostream>
#include<cstring>
using namespace std;
int a[205][205],f[20005],q[20005],n,m,i,st;
void init()
{
	int i,j,x,y;
	cin>>n>>m;
	memset(f,0,sizeof(f));
	for(i=1; i<=m; i++)
	{
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
	cin>>st;
}
void dfs(int i)   
{
	int j;
	cout<<i<<" ";
	f[i]=1;
	for(j=1; j<=n; j++)if((f[j]==0)&&(a[i][j]==1))dfs(j);
}
void bfs(int i)   
{
	int j,k,open,closed;
	memset(q,0,sizeof(q));
	open=0;
	closed=1;
	q[1]=i;
	cout<<i<<" ";
	f[i]=1;  
	while(open<closed)   
	{
		open++;
		k=q[open]; 
		for(j=1; j<=n; j++)
			if((a[k][j]==1)&&(f[j]==0))
			{
				cout<<j<<" ";
				f[j]=1;
				closed++;
				q[closed]=j;
			}
	}
}
int main()
{
	init();
	memset(f,0,sizeof(f));
	bfs(st);
}
