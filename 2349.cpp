#include<iostream>
using namespace std;
const int dirx[]={1,-1,0,0},diry[]={0,0,1,-1};
int map[20][20]={{0},{0}},n,m,sx,sy,ex,ey,ans=0;
void DFS(int x,int y)
{
	map[x][y]=0;
	if(x==ex&&y==ey) {ans++;return;}
	for(int i=0;i<4;i++)
	{
		int tx=x+dirx[i];
		int ty=y+diry[i];
		if(map[tx][ty]&&tx<=n&&ty<=m&&tx>=1&&ty>=1)
		{
			map[tx][ty]=0;
			DFS(tx,ty);
			map[tx][ty]=1;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&map[i][j]);
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	DFS(sx,sy);
	if(ans==0) ans=-1;
	printf("%d\n",ans);
	return 0;
}
