#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
struct node{int to,nx,val;}edge[200005];
int n,m,cnt=0,h[100005]={0},out[100005]={0},vis[100005]={0};
double f[100005]={0};
inline void Add(int x,int y,int z)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt,edge[cnt].val=z;}
void DFS(int x)
{
	if(vis[x]) return;
	vis[x]=1;
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		DFS(to);
		f[x]+=edge[i].val+f[to];
	}
	if(out[x]) f[x]/=out[x];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		Add(x,y,z);
		out[x]++;
	}
	DFS(1);
	printf("%.2lf",f[1]);
	return 0;
}
