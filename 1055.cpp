#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{int x,y,val;}pea[405];
int n,m,lim,maxx=0,mx=0,my=0,ans=0,cnt=0;
bool cmp(const node &a,const node &b)
{return a.val>b.val;}
int main()
{
//	freopen("peanut.in","r",stdin);
//	freopen("peanut.out","w",stdout);
	cin>>n>>m>>lim;
	for(int i=1;i<=n;i++)
		for(int j=1,a;j<=m;j++)
		{
			cin>>a;
			if(a)
			{
				pea[++cnt].x=i;
				pea[cnt].y=j;
				pea[cnt].val=a;
			}
		}
	sort(pea+1,pea+cnt+1,cmp);
	if(2*pea[1].x+1>lim) {cout<<0;return 0;}
	int lx=pea[1].x,ly=pea[1].y;
	lim-=lx+1,ans+=pea[1].val;
	for(int i=2;i<=cnt;i++)
	{ 
		if(lim<abs(pea[i].y-ly)+abs(pea[i].x-lx)||(lim-abs(pea[i].y-ly)-abs(pea[i].x-lx)-1)<pea[i].x) break;
		lim-=(abs(pea[i].y-ly)+abs(pea[i].x-lx)+1);
		lx=pea[i].x,ly=pea[i].y;
		ans+=pea[i].val;
	}
	cout<<ans;
	return 0;
}