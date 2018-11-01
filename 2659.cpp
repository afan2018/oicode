#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int l,r,cnt,fl;}seg[200005];
int n,m,L,R;
void Build(int l,int r,int num)
{
	seg[num].l=l;
	seg[num].r=r;
	seg[num].cnt=seg[num].fl=0;
	if(l==r) return;
	int mid=(l+r)/2;
	Build(l,mid,2*num);
	Build(mid+1,r,2*num+1);
}
void Insert(int num)
{
	if(L>seg[num].r||R<seg[num].l) return;
	if(seg[num].fl==1) return;
	if(L<=seg[num].l&&R>=seg[num].r)
	{
		seg[num].fl=1;
		seg[num].cnt=seg[num].r-seg[num].l+1;
		return;
	}
	if(seg[num].fl==-1)
	{
		seg[2*num].fl=seg[2*num+1].fl=-1;
		seg[2*num].cnt=seg[2*num+1].cnt=0;
		seg[num].fl=0;
	}
	Insert(2*num);
	Insert(2*num+1);
	seg[num].cnt=seg[2*num].cnt+seg[2*num+1].cnt;
}
void Delete(int num)
{
	if(L>seg[num].r||R<seg[num].l) return;
	if(seg[num].fl==-1) return;
	if(R>=seg[num].r&&L<=seg[num].l)
	{
		seg[num].fl=-1;
		seg[num].cnt=0;
		return;
	}
	if(seg[num].fl==1)
	{
		seg[2*num].fl=seg[2*num+1].fl=1;
		seg[2*num].cnt=seg[2*num].r-seg[2*num].l+1;
		seg[2*num+1].cnt=seg[2*num+1].r-seg[2*num+1].l+1;
		seg[num].fl=0;
	}
	Delete(2*num);
	Delete(2*num+1);
	seg[num].cnt=seg[2*num].cnt+seg[2*num+1].cnt;
}
int main()
{
	scanf("%d%d",&n,&m);
	Build(1,n-1,1);
	for(int i=1,fl,x,y;i<=m;i++)
	{
		scanf("%d%d%d",&fl,&L,&R);
		R--;
		if(fl==1) Insert(1);
		else Delete(1);
	}
	cout<<seg[1].cnt;
	return 0;
}