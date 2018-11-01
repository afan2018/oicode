#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct node{int pos,val;}Q[200005];
int n,m,L=1,R=1,sum[200005]={0},ans=0xcfcfcfcf;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,foo;i<=n;i++)
	{
		scanf("%d",&foo);
		sum[i]=sum[i-1]+foo;
		ans=max(ans,sum[i]-Q[L].val);
		while(L<=R&&Q[R].val>=sum[i]) R--;
		Q[++R].val=sum[i],Q[R].pos=i;
		while(L<=R&&Q[L].pos<=i-m) L++;
	}
	printf("%d",ans);
	return 0;
}