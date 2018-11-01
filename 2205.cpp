#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int x,y,r;double v;}gear[2055]={0};
int sta=0,fin=0,n,fx,fy;
double ans=10000;
bool Check(node a,node b)
{return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))==(a.r+b.r)*(a.r+b.r);}
void DFS(int x,int fa,double sum)
{
	double val=0;
	for(int i=1;i<=n;i++)
	{
		if(Check(gear[x],gear[i])&&i!=fa)
		{
			gear[i].v=val=gear[x].v*1.0/gear[i].r*gear[x].r;
			DFS(i,x,sum+val);
		}
	}
	if(x==fin) ans+=sum;
	return;
}
int main()
{
	cin>>n>>fx>>fy;
	for(int i=1;i<=n;i++)
	{
		cin>>gear[i].x>>gear[i].y>>gear[i].r;
		if(gear[i].x==gear[i].y&&gear[i].y==0) sta=i;
		else if(gear[i].x==fx&&gear[i].y==fy) fin=i;
	}
	gear[sta].v=10000;
	DFS(sta,0,0);
	cout<<int(ans);
	return 0;
}
