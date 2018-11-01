#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char map[205][205]= {'.'};
int sol=0,rest[1000]={0},resn=0,n,m,vis[205][205]= {0},tarx,tary,stax[1000],stay[1000],newx,newy,dirx[4]= {0,0,1,-1},diry[4]= {1,-1,0,0};
struct node{int x,y,tms;}quene[100005];
void init()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		{
			cin>>map[i][j];
			if(map[i][j]=='a')tarx=i,tary=j;
			if(map[i][j]=='r')stax[++resn]=i,stay[resn]=j;	
		}
}
void Rescue(int tarx,int tary)
{
	memset(vis,0,sizeof(vis));
	memset(quene,0,sizeof(quene));
	int head=0,tail=1;
	quene[1].x=tarx,quene[1].y=tary,quene[1].tms=0;
	vis[tarx][tary]=1;
	while(head<tail)
	{
		head++;
		int nowx=quene[head].x,nowy=quene[head].y;
		if(map[nowx][nowy]=='x')
		{
			map[nowx][nowy]='.';
			tail++;
			quene[tail].x=nowx;
			quene[tail].y=nowy;
			quene[tail].tms=quene[head].tms+1;
			vis[nowx][nowy]=1;
			continue;
		}
		for(int i=0; i<4; i++)
		{
			newx=quene[head].x+dirx[i];
			newy=quene[head].y+diry[i];
			for(int i=1;i<=resn;i++)
			{
				if(newx==stax[i]&&newy==stay[i])
				{
					cout<<quene[head].tms+1;
					return;
				}
			}
			if(newx<0||newx>m||newy<0||newy>n||vis[newx][newy]||map[newx][newy]=='#')continue;
			if(!vis[newx][newy])
			{
				tail++;
				quene[tail].x=newx;
				quene[tail].y=newy;
				quene[tail].tms=quene[head].tms+1;
				vis[newx][newy]=1;
			}
		}
	}
	cout<<"Poor ANGEL.";
}
int main()
{
	init();
	Rescue(tarx,tary);
	return 0;
}
/*
7 8
#.#####.
#.a#..r.
#..#x...
..#..#.#
#...##..
.#......
........
*/