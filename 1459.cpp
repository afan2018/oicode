#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{int x,y,num;}cow[100005];
int n,my,ans[100005]={0},c[100005]={0};
inline bool cmp(const node &a,const node &b)
{return a.x<b.x||(a.x==b.x&&a.y>b.y);}
void Init()
{
	for(int i=1;i<=n;i++)
	{
		cin>>cow[i].x>>cow[i].y;
		cow[i].num=i;
		cow[i].x++;
		cow[i].y++;
	}
	sort(cow+1,cow+n+1,cmp);
}
inline int Lowbit(int x)
{return x&(-x);}
int Insert(int x)
{
	for(int i=x;i<=100000;i+=Lowbit(i))
		c[i]++;
}
int Sum(int x)
{
	int ret=0;
	for(int i=x;i;i-=Lowbit(i))
		ret+=c[i];
	return ret;
}
void Solve()
{
	ans[cow[1].num]=0;
	my=cow[1].y;
	Insert(cow[1].y);
	for(int i=2;i<=n;i++)
	{
		if(cow[i].y==cow[i-1].y&&cow[i].x==cow[i-1].x)
			ans[cow[i].num]=ans[cow[i-1].num];
		else ans[cow[i].num]=Sum(my)-Sum(cow[i].y-1);
		Insert(cow[i].y);
		my=max(my,cow[i].y);
		
	}
}
int main()
{
	while(cin>>n)
	{
		if(n==0) break;
		memset(ans,0,sizeof(ans));
		memset(c,0,sizeof(c));
		Init();
		Solve();
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<' ';
		cout<<endl;
	}
	return 0;
}
/*
3
1 2
0 3
3 4
0
*/