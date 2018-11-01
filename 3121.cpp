#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct node{int l,r;}tree[100005];
int n,val[100005]={0},seq[100005]={0},cnt=0,a[100005]={0},top=0,S[100005]={0};
void DFS(int x)
{
	if(tree[x].l) DFS(tree[x].l);
	seq[++cnt]=x;
	if(tree[x].r) DFS(tree[x].r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",val+i);
	for(int i=1,x,fl;i<n;i++)
	{
		scanf("%d%d",&x,&fl);
		if(fl) tree[x].r=i+1;
		else tree[x].l=i+1;
	}
	DFS(1);
	for(int i=1;i<=n;i++) a[i]=val[seq[i]]-i;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=S[top]) S[++top]=a[i];
		else *upper_bound(S+1,S+top+1,a[i])=a[i];
	}
	printf("%d",n-top);
	return 0;
}
