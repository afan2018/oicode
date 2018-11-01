#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int val[7][7]=
{{0,0,0,0,0,0},
{0,1,1,1,1,1},
{0,0,1,1,1,1},
{0,0,0,-1,1,1},
{0,0,0,0,0,1,},
{0,0,0,0,0,0}};
int dirx[]={-1,-2,-2,-1,1,2,2,1},diry[]={-2,-1,1,2,-2,-1,1,2};
int map[7][7]={0},t,sx,sy,cnt=0,dep=0,suc=0;
string str;
void IDAStar(int d,int x,int y,int eva)
{
	if(eva==0) {suc=1;return;}
	if(d+eva>dep) return;//估价
	for(int i=0;i<=7;i++)
	{
		int tx=x+dirx[i];
		int ty=y+diry[i];
		if(tx>5||tx<1||ty>5||ty<1) continue;
		int neva=eva-(map[tx][ty]!=val[tx][ty])+(map[tx][ty]!=val[x][y]);
		swap(map[tx][ty],map[x][y]);
		IDAStar(d+1,tx,ty,neva);
		if(suc) return;
		swap(map[tx][ty],map[x][y]);
	}
}
int main()
{
	cin>>t;
	while(t--)
	{
		cnt=0;
		suc=0;
		for(int i=1;i<=5;i++)
		{
			cin>>str;
			str=' '+str;
			for(int j=1;j<=5;j++)
			{
				if(str[j]=='*')
				{
					map[i][j]=-1;
					sx=i;
					sy=j;
				}
				else map[i][j]=str[j]-'0';
				if(map[i][j]!=val[i][j]&&val[i][j]!=-1) cnt++;
			}
		}
		for(dep=0;dep<=15;dep++)
		{
			IDAStar(0,sx,sy,cnt);
			if(suc) break;
		}
		if(dep<=15) cout<<dep<<'\n';
			else cout<<"-1\n"; 
	}
	return 0;
}