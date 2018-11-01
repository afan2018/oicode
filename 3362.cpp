#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct node{int val,id;}a[1005];
int fa[1005]={0},sum[1005]={0},n,ans=0,cnt=0;
bool cmp(const node &a,const node &b)
{return a.val<b.val;}
inline int Getfa(int x)
{return x==fa[x]?x:fa[x]=Getfa(fa[x]);}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[2*i].val,&a[2*i-1].val);
		a[2*i].id=a[2*i-1].id=i;
	}
	for(int i=1;i<=n;i++) fa[i]=i,sum[i]=1;
	sort(a+1,a+2*n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		ans+=a[i].val*a[2*n-i+1].val;
		if(a[i].id!=a[2*n-i+1].id)
		{
			int fa1=Getfa(a[i].id),fa2=Getfa(a[2*n-i+1].id);
			if(fa1!=fa2)
			{
				fa[fa1]=fa2;
				sum[fa2]+=sum[fa1];
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(fa[i]==i) cnt+=sum[i]-1;
	printf("%d\n%d",ans,cnt);
	return 0;
}
