#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int l,r,val;}seg[300005];
int n,m,ans=0;
void Build(int l,int r,int num)
{
	seg[num].l=l,seg[num].r=r,seg[num].val=0;
	if(l==r) return;
	int mid=(l+r)/2;
	Build(l,mid,2*num);
	Build(mid+1,r,2*num+1);
}
void Insert(int x,int val,int num)
{
	if(x<seg[num].l||x>seg[num].r) return;
	if(x<=seg[num].r&&x>=seg[num].l)
		seg[num].val+=val;
	if(seg[num].l==seg[num].r) return;
	Insert(x,val,2*num);
	Insert(x,val,2*num+1);
}
void Sum(int l,int r,int num)
{
	if(r<seg[num].l||l>seg[num].r) return;
	if(r>=seg[num].r&&l<=seg[num].l)
	{
		ans+=seg[num].val;
		return;
	}
	Sum(l,r,2*num);
	Sum(l,r,2*num+1);
}
int main()
{
	cin>>n>>m;
	Build(1,n,1);
	for(int i=1,x,y;i<=m;i++)
	{
		string str;
		cin>>str>>x>>y;
		if(str=="Add") Insert(x,y,1);
		if(str=="Sub") Insert(x,-y,1);
		if(str=="Ask") {ans=0;Sum(x,y,1);cout<<ans<<endl;}
	}
	return 0;
}