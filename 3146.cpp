#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct node{int x,y,fl;}ans[10];
int map[10][10]={{0},{0}},n,tot[15]={0};
void Drop()
{
	for(int i=1;i<=5;i++)
	{
		int t=0;
		for(int j=1;j<=7;j++)
			if(map[i][j])
			{
				int tmp=map[i][j];
				map[i][j]=0;
				map[i][++t]=tmp;
			}
	}
}
bool Clear()
{
	Drop();
	int flag[10][10]={{0},{0}};
	for(int i=1;i<=5;i++)
		for(int j=1;j<=7;j++)
		{
			if(i<=3&&map[i][j]&&map[i][j]==map[i+1][j]&&map[i+1][j]==map[i+2][j])
				flag[i][j]=flag[i+1][j]=flag[i+2][j]=1;
			if(j<=5&&map[i][j]&&map[i][j]==map[i][j+1]&&map[i][j+1]==map[i][j+2])
				flag[i][j]=flag[i][j+1]=flag[i][j+2]=1;
		}
	bool ret=0;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=7;j++)
			if(flag[i][j])
			{
				ret=1;
				tot[map[i][j]]--;
				map[i][j]=0;
			}
	return ret;
}
bool Judge()
{
	for(int i=1;i<=5;i++)
		for(int j=1;j<=7;j++)
			if(map[i][j])
				return false;
	return true;
}
bool DFS(int dep)
{
	if(dep>n) return Judge();
	for(int i=1;i<=10;i++)
		if(tot[i]==2||tot[i]==1)
			return false;
	int temp[10][10]={{0},{0}},tmp[15]={0};
	memcpy(temp,map,sizeof(map));
	memcpy(tmp,tot,sizeof(tot));
	for(int i=1;i<=5;i++)
		for(int j=1;j<=7;j++)
		{
			if(map[i][j]==0) break;
			if(i<5)
			{
				ans[dep].x=i,ans[dep].y=j,ans[dep].fl=1;
				swap(map[i][j],map[i+1][j]);
				while(Clear());
				if(DFS(dep+1)) return true;
				memcpy(map,temp,sizeof(map));
				memcpy(tot,tmp,sizeof(tmp));
			}//讨论交换，向左交换与向右交换或向右侧空位移动都用右移动表示
			if(i>1&&map[i-1][j]==0)
			{
				ans[dep].x=i,ans[dep].y=j,ans[dep].fl=-1;
				swap(map[i][j],map[i-1][j]);
				while(Clear());
				if(DFS(dep+1)) return true;
				memcpy(map,temp,sizeof(map));
				memcpy(tot,tmp,sizeof(tmp));
			}//向左交换已经讨论，还剩向左方空位移动
		}
	return false;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=5;i++)
	{
		int t=0;
		while(scanf("%d",&x)==1&&x)
		{
			map[i][++t]=x;
			tot[x]++;
		}
	}
	if(DFS(1))
		for(int i=1;i<=n;i++)
			printf("%d %d %d\n",ans[i].x-1,ans[i].y-1,ans[i].fl);
	else puts("-1");
	return 0;
}