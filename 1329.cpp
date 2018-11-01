#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{int x,y;}p[100005];
int n,c[300005]={0},ans[100005]={0},my=0;
inline bool cmp(const node &a,const node &b)
{return (a.x<b.x)||(a.x==b.x&&a.y<b.y);}
inline int Lowbit(int x)
{return x&(-x);}
void Insert(int pos)
{
	for(int i=pos;i<=my;i+=Lowbit(i))
		c[i]++;
}
int Sum(int pos)
{
	int ret=0;
	for(int i=pos;i>0;i-=Lowbit(i))
		ret+=c[i];
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].x++;
		p[i].y++;
		my=max(my,p[i].y);
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		ans[Sum(p[i].y)]++;
		Insert(p[i].y);
	}
	for(int i=0;i<n;i++)
		printf("%d\n",ans[i]);
	return 0;
}