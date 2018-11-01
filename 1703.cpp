#include<iostream>
using namespace std;
struct node{int next,to;}edge[20005];
int h[20005]={0},n,m,a,b,k,cnt=0,vis[20005]={0},ans=0;
void AddEdge(int x,int y)
{edge[++cnt].to=y,edge[cnt].next=h[x],h[x]=cnt;
edge[++cnt].to=x,edge[cnt].next=h[y],h[y]=cnt;}
void DFS(int x)
{
	vis[x]=1;
	for(int i=h[x];i;i=edge[i].next)
		if(!vis[edge[i].to])DFS(edge[i].to);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a>>b,AddEdge(a,b);
	for(int i=1;i<=n;i++)
		if(!vis[i])DFS(i),ans++;
	cout<<ans;
	return 0;
}