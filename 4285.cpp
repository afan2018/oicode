#include<iostream>
#include<cstdio>
using namespace std;
const int MOD (10007);
struct node{int to,nx;}edge[400005];
int cnt=0,h[400005]={0},n,val[200005]={0},max1=0,max2=0,sum=0,ans1=0,ans2=0;
inline void Add(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("link.in","r",stdin);
	freopen("link.out","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		Add(x,y);
		Add(y,x);
	}
	for(int i=1;i<=n;i++) scanf("%d",val+i);
	for(int i=1;i<=n;i++)
	{
		max1=max2=sum=0;
		for(int j=h[i];j;j=edge[j].nx)
		{
			int to=edge[j].to;
			if(val[to]>max1) max2=max1,max1=val[to];
			else if(val[to]>max2) max2=val[to];
			sum=(sum+val[to])%MOD;
		}
		ans1=max(ans1,max1*max2);
		for(int j=h[i];j;j=edge[j].nx)
		{
			int to=edge[j].to;
			ans2=((ans2+(val[to]%MOD)*((sum-val[to])%MOD)+MOD)%MOD);
		}
	}
	printf("%d %d",ans1,ans2);
	return 0;
}