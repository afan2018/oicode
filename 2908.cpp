#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{int fr,to,val;}edge[2500005];
struct point{int x,y;}p[55];
int n,cnt=0,fa[55]={0};
int afanbs(int x)
{return x>0?x:-x;}
int Get(int a,int b)
{return (afanbs(p[a].x-p[b].x)+afanbs(p[a].y-p[b].y)+1)/2;}
bool cmp(node x,node y)
{return x.val<y.val;}
int Getfa(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=Getfa(fa[x]);
}
void K()
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(edge+1,edge+cnt+1,cmp);
	int ccnt=0;
	for(int i=1;i<=cnt;i++)
	{
		int a=Getfa(edge[i].fr),b=Getfa(edge[i].to);
		if(a==b) continue;
		ccnt++;
		fa[a]=b;
		if(ccnt==n-1)
		{
			cout<<edge[i].val;
			return;
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			edge[++cnt].fr=i;
			edge[cnt].to=j;
			edge[cnt].val=Get(i,j);
		}
	K();
	return 0;
}
