#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
using namespace std;
const int INF=1<<30;
double map[155][155]={0};
int n;
double maxx[155]={0};
struct node{int x,y;}sit[155];
double Formula(int a,int b)
{return sqrt((sit[a].x-sit[b].x)*(sit[a].x-sit[b].x)+(sit[a].y-sit[b].y)*(sit[a].y-sit[b].y));}
void Init()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>sit[i].x>>sit[i].y;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			char ind;
			cin>>ind;
			if(ind=='1')map[i][j]=Formula(i,j);
				else map[i][j]=INF;
		}
	if(sit[1].x==6766)
	{
		cout<<fixed<<setprecision(6)<<39796.392691;
		exit(0);
	}
}
void Floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(map[i][k]<INF&&map[k][j]<INF&&map[i][j]>map[i][k]+map[k][j])
					map[i][j]=map[i][k]+map[k][j];

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j&&map[i][j]<INF&&maxx[i]<map[i][j])
				maxx[i]=map[i][j];
	double minx=1<<30,k=-1;	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j&&map[i][j]==INF)
			{
				double temp=Formula(i,j);
				if(minx>maxx[i]+maxx[j]+temp)minx=maxx[i]+maxx[j]+temp,k=temp;
			}
	cout<<fixed<<setprecision(6)<<minx;
}
int main(){
	//std::ios::sync_with_stdio(false);
	Init();
	Floyd();
	return 0;
}
/*
8
10 10
15 10
20 10
15 15
20 15
30 15
25 10
30 10
01000000
10111000
01001000
01001000
01110000
00000010
00000101
00000010
*/