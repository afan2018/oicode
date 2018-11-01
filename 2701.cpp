#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int to,nx;}edge[500005];
int m,RMQ[100005][35]={{0},{0}},h[100005]={0},cnt=0,n,root,Euler[100005]={0},Dep[100005]={0},First[50005]={0},sign=0;
void Add(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
void DFS(int x,int dep)
{
	Euler[++sign]=x;
	Dep[sign]=dep;
	First[x]=sign;
	for(int i=h[x];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		DFS(to,dep+1);
		Euler[++sign]=x;
		Dep[sign]=dep;
	}
}
void ST()
{
	int m=sign;
	for(int i=1;i<=m;i++) RMQ[i][0]=i;
	for(int j=1;j<=int(log2(m));j++)
		for(int i=1;i+(1<<j)-1<=m;i++)
		{
			if(Dep[RMQ[i][j-1]]<Dep[RMQ[i+(1<<(j-1))][j-1]])
				RMQ[i][j]=RMQ[i][j-1];
			else RMQ[i][j]=RMQ[i+(1<<(j-1))][j-1];
		}
}
void Query()
{
	int x1,x2;
	scanf("%d%d",&x1,&x2);
	if(First[x1]>First[x2]) swap(x1,x2);
	x1=First[x1],x2=First[x2];
	int idx=int(log2(x2-x1+1));
	int ans=min(Dep[RMQ[x1][idx]],Dep[RMQ[x2-(1<<idx)+1][idx]]);
	printf("%d\n",ans);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,num,x;i<=n;i++)
	{
		scanf("%d",&num);
		for(int j=1;j<=num;j++)
		{
			scanf("%d",&x);
			Add(i,x);
		}
	}
	DFS(1,1);
	ST();
	scanf("%d",&m);
	for(int i=1;i<=m;i++) Query();
	return 0;
}