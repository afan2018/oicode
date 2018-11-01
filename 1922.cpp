#include<iostream>
#include<cmath>
#include<iomanip>
const int INF=1e8;
using namespace std;
struct snake{int x,y;}sit[205];
struct block{int x1,x2,y1,y2;}line[105];
int n,m;
double ans=0,map[205][205]={0};
int Cross(int x1,int y1,int x2,int y2,int x3,int y3)
{return (x1-x3)*(y2-y3)-(y1-y3)*(x2-x3);}
bool Judge(int a,int b,int c)
{
	int v1=Cross(sit[a].x,sit[a].y,line[c].x2,line[c].y2,line[c].x1,line[c].y1)*Cross(sit[b].x,sit[b].y,line[c].x2,line[c].y2,line[c].x1,line[c].y1);
	int v2=Cross(line[c].x1,line[c].y1,sit[b].x,sit[b].y,sit[a].x,sit[a].y)*Cross(line[c].x2,line[c].y2,sit[b].x,sit[b].y,sit[a].x,sit[a].y);
	return (v1<0&&v2<0);
}
double Calc(int x,int y)
{
	return sqrt((double)(sit[x].x-sit[y].x)*(sit[x].x-sit[y].x)+(sit[x].y-sit[y].y)*(sit[x].y-sit[y].y));
}
void Init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>sit[i].x>>sit[i].y;
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>line[i].x1>>line[i].y1>>line[i].x2>>line[i].y2;	
}
void Prim()
{
	int cnt=0,vst[201]={0},k;
	double minn=0,dis[201]={0};
	for(int i=1;i<=n;i++)dis[i]=map[1][i];
	vst[1]=1;
	for(int i=1;i<=n;i++)
	{
		minn=INF;
		for(int j=1;j<=n;j++)
			if(dis[j]<minn&&!vst[j])
				minn=dis[j],k=j;
		if(minn==INF)break;
		cnt++;
		vst[k]=1;
		ans+=minn;
		for(int j=1;j<=n;j++)
			if(map[k][j]<dis[j]&&!vst[j])
				dis[j]=map[k][j];
	}
	if(cnt<n-1)cout<<"-1.000";
	else cout<<fixed<<setprecision(3)<<ans;
}
int main(){
	Init();
	int fl=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			fl=1;
			for(int k=1;k<=m;k++)
				if(Judge(i,j,k))
				{
					map[i][j]=map[j][i]=INF;
					fl=0;
					break;
				}
			if(fl) map[i][j]=map[j][i]=Calc(i,j);
		}	
	Prim();
	return 0;
}
/*
3
1 3
3 1
5 5
1
0 0 3 3
*/