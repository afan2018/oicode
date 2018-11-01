#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct fans{int h,cnt;}a[100005];
struct node{int l,r,rest;}seg[400005];
int n,ans[100005]={0};
inline bool cmp(const fans &a,const fans &b)
{return a.h<b.h;}
void Build(int x,int l,int r)
{
	seg[x].l=l,seg[x].r=r;
	seg[x].rest=r-l+1;
	if(l==r) return;
	int mid=(l+r)>>1;
	Build(2*x,l,mid);
	Build(2*x+1,mid+1,r);
}
int Find(int x,int val)
{
	if(seg[x].l==seg[x].r) return seg[x].l;
	if(val>seg[2*x].rest) return Find(2*x+1,val-seg[2*x].rest);
	return Find(2*x,val);
}
void Modify(int x,int pos,int val)
{
	if(seg[x].l>pos||seg[x].r<pos) return;
	seg[x].rest--;
	if(seg[x].l==seg[x].r)
	{
		ans[pos]=val;
		return;
	}
	Modify(2*x,pos,val);
	Modify(2*x+1,pos,val);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].h,&a[i].cnt);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		if(a[i].cnt>n-i) {puts("impossible");return 0;}
	Build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		int pos=Find(1,min(a[i].cnt,n-i-a[i].cnt)+1);
		Modify(1,pos,a[i].h);
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}