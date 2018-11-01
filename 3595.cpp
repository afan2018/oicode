#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,map[505][505]={0},belong[505][505]={0},ru=0,chu=0,scc=0;
int h[4]={-1,0,1,0},s[4]={0,1,0,-1};
bool r[505*505]={false},c[505*505]={false};
struct node{int x=0,y=0;}q[505*505];
void bfs(int a,int b,int o)
{
	q[1].x=a;q[1].y=b;
	int op=0,ed=1;
	while(op<ed)
	{
		++op;
		int x=q[op].x,y=q[op].y;
		for(int i=0;i<=3;i++)
		{
			if(!belong[x+h[i]][y+s[i]]&&map[x][y]==map[x+h[i]][y+s[i]]&&map[x+h[i]][y+s[i]]!=-1)
			{
				q[++ed].x=x+h[i];
				q[ed].y=y+s[i];
				belong[q[ed].x][q[ed].y]=o;
			}		
		}
	}
}
int main()
{
	memset(map,-1,sizeof(map));
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&map[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!belong[i][j])
			{
				belong[i][j]=++scc;
				bfs(i,j,scc);
			}
	if(scc==1) {cout<<0;return 0;}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<=3;k++)
			{
				if(map[i][j]>=map[i+h[k]][j+s[k]]&&belong[i][j]!=belong[i+h[k]][j+s[k]]&&map[i+h[k]][j+s[k]]!=-1)
				{
					c[belong[i][j]]=true;
					r[belong[i+h[k]][j+s[k]]]=true;
				}
			}
	for(int i=1;i<=scc;i++)
	{	
		if(!c[i]) chu++;
		if(!r[i]) ru++;
		//cout<<"Scc:"<<i<<" "<<c[i]<<" "<<r[i]<<endl;
	}
	cout<<max(ru,chu);
	//cout<<chu<<" "<<ru<<" "<<scc<<endl;
	/*
	for(int i=1;i<=n;i++)
		{for(int j=1;j<=m;j++)
			cout<<belong[i][j]<<" ";
			cout<<endl;}
	*/
 	return 0;
}
/*
9 3
1 1 1 2 2 2 1 1 1
1 2 1 2 3 2 1 2 1
1 1 1 2 2 2 1 1 1
*/