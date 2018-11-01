#include<iostream>
#include<iomanip>
#include<algorithm>
#include<map>
#include<cstdio>
using namespace std;
int n,cnt=0,l=1,r=0,vcnt=0,ans=0x3f3f3f3f,num[50005]={0};
map<int,int>dis;
struct node{int x,var;}cow[50005];
inline bool cmp(const node &a,const node &b)
{return a.x<b.x;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>cow[i].x>>cow[i].var;
		cow[i].var=(!dis[cow[i].var]?dis[cow[i].var]=++cnt:dis[cow[i].var]);
	}
	sort(cow+1,cow+n+1,cmp);
	while(r<=n)
	{
		if(l<=r&&vcnt==cnt) ans=min(ans,cow[r].x-cow[l].x);
		if(vcnt<cnt) 
		{
			r++;
			if(!num[cow[r].var]) vcnt++;
			num[cow[r].var]++;
		}
		else
		{
			num[cow[l].var]--;
			if(!num[cow[l].var]) vcnt--;
			l++;
		}
	}
	cout<<ans;
	return 0;
}