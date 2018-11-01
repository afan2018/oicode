#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int l,r,sum,val;}seg[4000000];
int n,m,fail;
inline int Getint()
{
	int fl=1,ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') if(ch=='-') fl=-1,ch=getchar();
	while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*fl;
}
void Build(int x,int l,int r)
{
	seg[x].sum=0;
	seg[x].l=l;
	seg[x].r=r;
	if(l==r)
	{
		seg[x].val=Getint();
		return;
	}
	int mid=(l+r)/2;
	Build(2*x,l,mid);
	Build(2*x+1,mid+1,r);
	seg[x].val=min(seg[2*x].val,seg[2*x+1].val);
}
void Pushdown(int x)
{
	seg[2*x].sum+=seg[x].sum;
	seg[2*x+1].sum+=seg[x].sum;
	seg[2*x].val-=seg[x].sum;
	seg[2*x+1].val-=seg[x].sum;
	seg[x].sum=0;
}
void Modify(int x,int l,int r,int val)
{
	if(fail) return;
	if(seg[x].l>r||seg[x].r<l) return;
	if(seg[x].l>=l&&seg[x].r<=r)
	{
		if(seg[x].val<val) {fail=1;return;}
		seg[x].sum+=val;
		seg[x].val-=val;
		return;
	}
	Pushdown(x);
	Modify(2*x,l,r,val);
	Modify(2*x+1,l,r,val);
	seg[x].val=min(seg[2*x].val,seg[2*x+1].val);
}
int main()
{
	n=Getint();
	m=Getint();
	Build(1,1,n);
	for(int i=1,val,l,r;i<=m;i++)
	{
		fail=0;
		val=Getint();
		l=Getint();
		r=Getint();
		Modify(1,l,r,val);
		if(fail) {printf("-1\n%d",i);return 0;}
	}
	puts("0");
	return 0;
}
