#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int l,r,val;}seg[3000005];
int n,m,ans=0;
void Build(int l,int r,int num)
{
	seg[num].l=l,seg[num].r=r,seg[num].val=0;
	if(l==r) return;
	int mid=(l+r)/2;
	Build(l,mid,2*num);
	Build(mid+1,r,2*num+1);
}
void Insert(int l,int r,int num)
{
	if(r<seg[num].l||l>seg[num].r) return;
	if(l<=seg[num].l&&r>=seg[num].r)
	{
		seg[num].val++;
		return;
	}
	Insert(l,r,2*num);
	Insert(l,r,2*num+1);
}
void Ask(int x,int num)
{
	if(x<seg[num].l||x>seg[num].r) return;
	if(x<=seg[num].r&&x>=seg[num].l)
		ans+=seg[num].val;
	if(seg[num].l==seg[num].r) return;
	Ask(x,2*num);
	Ask(x,2*num+1);
}
int main()
{
	scanf("%d%d",&n,&m);
	Build(1,n,1);
	for(int i=1,x,y,fl;i<=m;i++)
	{
		scanf("%d",&fl);
		if(fl==1)
		{
			scanf("%d%d",&x,&y);
			Insert(x,y,1);
		}
		else
		{
			ans=0;
			scanf("%d",&x);
			Ask(x,1);
			ans%=2;
			printf("%d\n",ans);
		}
	}
	return 0;
}