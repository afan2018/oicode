#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{int x,y;}cow[10005];
int n,dirx[]={0,0,1,-1},diry[]={1,-1,0,0},ans=0;
bool cmpx(const node a,const node b)
{return a.x<b.x;}
bool cmpy(const node a,const node b)
{return a.y<b.y;}
int Check(int x,int y)
{
	for(int i=1;i<=n;i++)
		if(cow[i].x==x&&cow[i].y==y)
			return 0;
	return 1;
}
int Calc(int x,int y)
{
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=abs(cow[i].x-x)+abs(cow[i].y-y);
	return sum;
}
int main()
{
//	freopen("nbarn.in","r",stdin);
//	freopen("nbarn.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>cow[i].x>>cow[i].y;
	if(n%2==1)
	{
		sort(cow+1,cow+n+1,cmpx);
		int ansx=cow[n/2+1].x;
		sort(cow+1,cow+n+1,cmpy);
		int ansy=cow[n/2+1].y;
		if(Check(ansx,ansy)==1) 
		{
			cout<<Calc(ansx,ansy)<<' '<<1;
			return 0;
		}
		else
		{
			int dis=0x7fffffff;
			int cnt=0;
			for(int i=0;i<=3;i++)
			{
				int nx=ansx+dirx[i];
				int ny=ansy+diry[i];
				int ndis=Calc(nx,ny);
				if(ndis<dis) 
				{
					dis=ndis;
					cnt=1;
				}
				else if(ndis==dis) cnt++;
			}
			cout<<dis<<' '<<cnt;
			return 0;
		}
	}
	else
	{
		int sum=0;
		sort(cow+1,cow+n+1,cmpx);
		int mx1=cow[n/2].x,mx2=cow[n/2+1].x;
		sort(cow+1,cow+n+1,cmpy);
		int my1=cow[n/2].y,my2=cow[n/2+1].y;
		int ans=(mx2-mx1+1)*(my2-my1+1);
		for(int i=1;i<=n;i++)
		{
			if(cow[i].x>=mx1&&cow[i].x<=mx2&&cow[i].y>=my1&&cow[i].y<=my2) ans--;
            sum+=abs(mx1-cow[i].x)+abs(my1-cow[i].y);
		}
		cout<<sum<<' '<<ans;
		return 0;
	}
	return 0;
}