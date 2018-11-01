#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct Node{int pos,val;}Up[200005],Down[200005];
struct node{int to,nx,val;}edge[400005];
int n,m,h[200005]={0},cnt=0,dis[200005]={0},foo=0,Q[200005]={0},L=0,R=0,ans=0,up[200005]={0},d[200005][2]={{0}};
void Add(int x,int y,int z)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt,edge[cnt].val=z;}
void DFS1(int x,int fa)
{
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		if(to==fa) continue;
		DFS1(to,x);
		if(edge[i].val+d[to][0]>d[x][0])
		{
			d[x][1]=d[x][0];
			d[x][0]=edge[i].val+d[to][0];
		}
		else d[x][1]=max(d[x][1],edge[i].val+d[to][0]);
	}
}
void DFS2(int x,int fa)
{
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		if(to==fa) continue;
		up[to]=max(up[x]+edge[i].val,edge[i].val+d[x][edge[i].val+d[to][0]==d[x][0]]);
		DFS2(to,x);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=2,x,y;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		Add(x,i,y);
		Add(i,x,y);
	}
	DFS1(1,0);
	DFS2(1,0);
	for(int i=1;i<=n;i++) dis[i]=max(d[i][0],up[i]);
	int ul=1,ur=0,dl=1,dr=0;
	for(int i=1;i<=n;i++)
	{
		while(ul<=ur&&Up[ur].val>=dis[i]) ur--;
		while(dl<=dr&&Down[dr].val<=dis[i]) dr--;
		Up[++ur].val=dis[i],Up[ur].pos=i;
		Down[++dr].val=dis[i],Down[dr].pos=i;
		while(ul<=ur&&dl<=dr&&abs(Up[ul].val-Down[dl].val)>m)
		(Up[ul].pos<Down[dl].pos)?ul++:dl++;
		ans=max(ans,i-max(Up[ul-1].pos+1,Down[dl-1].pos+1)+1);
	}
	printf("%d",ans);
	return 0;
}
