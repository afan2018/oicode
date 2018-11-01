#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct node{int to,nx;}edge[200005];
struct nodee{int num,tms;};
queue<nodee>q;
int n,m,cnt=0,h[100005]={0},sta=0,vis[100005]={0};
void Addedge(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
int ans=0;
void BFS()
{
	q.push({sta,0});
	vis[sta]=1;
	while(!q.empty())
	{
		nodee x=q.front();
		int xx=x.num;
		q.pop();
		for(int i=h[xx];i;i=edge[i].nx)
		{
			int to=edge[i].to;
			if(!vis[to])
			{	
				q.push({to,x.tms+1});
				ans=max(ans,x.tms+1);
				vis[to]=1;
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1,a,b;i<=m;i++)
		cin>>a>>b,Addedge(a,b),Addedge(b,a);
	cin>>sta;
	BFS();
	cout<<ans+1<<endl;
	return 0;
}
/*
4 4
1 2
2 3
3 4
2 4
1
*/