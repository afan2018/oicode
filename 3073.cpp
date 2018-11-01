#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
const int dirx[]={0,0,-1,1},diry[]={1,-1,0,0};
int map[1005][1005]={0},n,m,sx,sy,vis[1005][1005]={0},cnt=0;
struct node{int x,y,step;}q[200005];
int ha[200005];
void BFS()
{
	int head=1,tail=1;
	q[head].x=sx,q[head].y=sy;
	q[head].step=0;
	vis[sx][sy]=1;
	while(head<=tail)
	{
		for(int i=0;i<=3;i++)
		{
			int nx=q[head].x+dirx[i];
			int ny=q[head].y+diry[i];
			if(!vis[nx][ny])
			{
				vis[nx][ny]=1;
				q[++tail].x=nx;
				q[tail].y=ny;
				q[tail].step=q[head].step+1;
				if(map[nx][ny]==2) ha[q[tail].step]++,cnt++;
				if(map[nx][ny]==1)
				{
					cout<<cnt-ha[q[tail].step];
					return;
				}
			}
		}
		head++;
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>map[i][j];
			if(map[i][j]==3) sx=i,sy=j;
		}
	BFS();
	return 0;
}
/*
6 5
0 0 3 0 0
0 2 0 0 0
0 0 2 0 1
0 0 1 0 0
1 0 0 0 0
0 0 0 2 0
*/