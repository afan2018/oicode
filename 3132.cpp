#include<iostream>
#include<iomanip>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
priority_queue<int,vector<int> >heap;
int cnt=0,n,m,k,fa[100005]={0},x,y,maxx=1,ha[100005]={0},num[100005]={0};
int Get(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=Get(fa[x]);
}
void Union(int x,int y)
{
	int a=Get(x),b=Get(y);
	if(a==b) return;
	fa[a]=b;
	num[b]+=num[a];
	num[a]=num[b];
	heap.push(num[a]);
}
int main(){
	scanf("%d%d",&n,&m);
	cnt=n;
	for(int i=1;i<=n;i++)
		fa[i]=i,num[i]=1;
	heap.push(1);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d%d",&x,&y);
			Union(x,y);
		}
		else if(k==2) printf("%d\n",heap.top());
	}
	return 0;
}
