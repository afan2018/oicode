#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
struct node{int val,occ;}dp[550000];
int n,W,cat[20]={0};
int main()
{
	scanf("%d%d",&n,&W);
	for(int i=1;i<=n;i++) scanf("%d",cat+i);
	for(int i=1;i<(1<<n);i++) dp[i].val=0x3f3f3f3f;
	dp[0].val=1;
	for(int i=0;i<(1<<n);i++)
		for(int j=1;j<=n;j++)
		{
			if(i&(1<<(j-1))) continue;
			int newi=(i|(1<<(j-1)));
			node foo;
			if(dp[i].occ+cat[j]>W) foo.val=dp[i].val+1,foo.occ=cat[j];
			else foo.val=dp[i].val,foo.occ=dp[i].occ+cat[j];
			if(foo.val<dp[newi].val||(foo.val==dp[newi].val&&foo.occ<dp[newi].occ)) dp[newi]=foo;
		}
	printf("%d",dp[(1<<n)-1]);
	return 0;
}
