#include<iostream>
#include<cstring>
using namespace std;
struct node{int x,y;}q[1000005];
int h=0,t=0,n,m,p[1005][1005]={0},dx[4]={0,1,-1,0},dy[4]={1,0,0,-1};
bool vis[1005][1005]={0};
bool BFS(int x)
{
	memset(vis,0,sizeof(vis));
	memset(q,0,sizeof(q));
	h=0,t=1;
	q[1].x=1,q[1].y=1;
	vis[1][1]=1;
	while(h!=t)
	{
		h++;
		for(int i=0;i<4;i++)
		{
			int nx=q[h].x+dx[i],ny=q[h].y+dy[i];
			if(nx>0&&ny>0&&nx<=n&&ny<=m&&p[nx][ny]<=x&&!vis[nx][ny])
			{
				q[++t].x=nx,q[t].y=ny;
				vis[nx][ny]=1;
				if(nx==n) return true;
			}
		}
	}
	return false;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>p[i][j];
	int l=1,r=1001,mid,ans;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(BFS(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}