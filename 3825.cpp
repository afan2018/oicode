#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MOD (99999997);
struct node{int id,val;}seqa[100005],seqb[100005];
int n,tree[300005]={0},c[100005]={0},ans=0;
inline bool cmp(const node &a,const node &b)
{return a.val<b.val;}
inline int Lowbit(int x)
{return x&(-x);}
void Add(int x)
{
	for(int i=x;i<=n;i+=Lowbit(i)) tree[i]++; 
}
int Sum(int x)
{
	int ret=0;
	for(int i=x;i>0;i-=Lowbit(i)) ret=(ret+tree[i])%MOD;
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&seqa[i].val),seqa[i].id=i;
	for(int i=1;i<=n;i++)
		scanf("%d",&seqb[i].val),seqb[i].id=i;
	sort(seqa+1,seqa+n+1,cmp);
	sort(seqb+1,seqb+n+1,cmp);
	for(int i=1;i<=n;i++)
		c[seqb[i].id]=seqa[i].id;
	for(int i=1;i<=n;i++)
	{
		Add(c[i]);
		ans=(ans+(i%MOD-Sum(c[i])%MOD)%MOD)%MOD;
	}
	printf("%d",ans);
	return 0;
}