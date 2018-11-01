#include<cstdio>
#include<iostream>
using namespace std;
struct node{int nx,to;}edge[400005]={0};
int n,h[200005]={0},cnt=0,dmax[200005]={0},dsec[200005]={0},maxx=0;
void Addedge(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
int Getint()
{
	int bj=1,ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') bj=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*bj;
}
void DFS(int x,int fa)
{
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		if(to==fa) continue;
		DFS(to,x);
		if(dmax[to]+1>dmax[x])
		{
			dsec[x]=dmax[x];
			dmax[x]=dmax[to]+1;
		}
		else dsec[x]=max(dsec[x],dmax[to]+1);
	}
	maxx=max(maxx,dmax[x]+dsec[x]);
}
int main()
{
	n=Getint();
	for(int i=1,x,y;i<n;i++)
	{
		x=Getint();
		y=Getint();
		Addedge(++x,++y);
		Addedge(y,x); 
	}
	DFS(1,0);
	printf("%d",maxx);
	return 0;
}