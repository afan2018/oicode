#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int nx,to;}edge[200005];
int h[100005]={0},cnt=0,n,val[100005]={0},f[100005][2]={0};
inline void Addedge(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
void DP(int x,int fa)
{
	f[x][1]=val[x];
	f[x][0]=0;
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		if(to==fa) continue;
		DP(to,x);
		f[x][1]+=f[to][0];
		f[x][0]+=max(f[to][0],f[to][1]);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>val[i];
	for(int i=1,x,y;i<n;i++)
		cin>>x>>y,Addedge(x,y),Addedge(y,x);
	DP(1,0);
	cout<<max(f[1][0],f[1][1]);
	return 0;
}
