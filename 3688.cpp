#include<iostream>
#include<iomanip>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
queue<int>Q;
int map[255][255]={0},n,m1=0,m2=0,fa[255]={0},vis[255]={0},dis[255]={0};
struct Heng
{
	int x1,x2,y;
}w1[1005]={0};
struct Zong
{
	int y1,y2,x;
}w2[1005]={0};
int Cul()
{
	int i,j;
	for(i=1;i<=m1;i++) {
		for(j=1;j<=m2;j++) {
			if(w1[i].y>w2[j].y2||w1[i].y<w2[j].y1) continue;
			if(w1[i].x1>w2[j].x||w1[i].x2<w2[j].x) continue;
            map[i][j+m1]=1;
		}
	} 
	return 0;
}

bool SPFA()
{
	while(!Q.empty()) Q.pop();
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	memset(fa,0,sizeof(fa));
	vis[n+1]=1;
	dis[n+1]=0;
	Q.push(n+1);
	while(!Q.empty())
	{
		int fr=Q.front();
		vis[fr]=0;
		Q.pop();
		for(int i=1;i<=n+2;i++)
		{
			if(map[fr][i]>0&&dis[fr]+1<dis[i])
			{
				dis[i]=dis[fr]+1;
				fa[i]=fr;
				if(!vis[i])
				{
					vis[i]=1;
					Q.push(i);
				}
			}
		}
	}
	if(dis[n+2]!=0x3f3f3f3f) return 1;
	return 0;
}
int EK()
{
	int ans=0;
	while(SPFA())
	{
		int minn=0x3f;
		int j=n+2;
		while(1)
		{
			if(j==n+1) break;
			minn=min(minn,map[fa[j]][j]);
			j=fa[j];
		}
		j=n+2;
		ans+=minn;
		while(1)
		{
			if(j==n+1) break;
			map[fa[j]][j]-=minn;
			map[j][fa[j]]+=minn;
			j=fa[j];
		}
	}
	return ans;
}
int main()
{
	int i,j,x1,x2,y1,y2,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2) {
			m2++;
			if(y1>y2) {
				j=y1;y1=y2;y2=j;
			}
			w2[m2].y1=y1;w2[m2].y2=y2;w2[m2].x=x1;
		}
		else if(y1==y2) {
			m1++;
			if(x1>x2) {
				j=x1;x1=x2;x2=j;
			}
			w1[m1].x1=x1;w1[m1].x2=x2;w1[m1].y=y1;
		}
	}
	Cul();
	for(int i=1;i<=m1;i++)
		map[n+1][i]=1;
		
	for(int i=1;i<=m2;i++)
		map[i+m1][n+2]=1;
	cout<<n-EK();
return 0;
}
