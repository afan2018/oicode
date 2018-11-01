#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct node{int val,pos;}Q[400005];
int n,limL,limR,L=1,R=0,dp[400005]={0},seq[400005]={0},ans=0xcfcfcfcf;
int main()
{
	scanf("%d%d%d",&n,&limL,&limR);
	for(int i=0;i<=n;i++) scanf("%d",seq+i);
	Q[++R].pos=Q[R].val=0;
	for(int i=limL;i<=n+limR;i++)
	{
		while(L<=R&&Q[R].val<=dp[i-limL]) R--;
		Q[++R].val=dp[i-limL],Q[R].pos=i-limL;
		while(L<=R&&Q[L].pos<i-limR) L++;
		dp[i]=max(dp[i],Q[L].val+seq[i]);
	}
	for(int i=n;i<=n+limR;i++) ans=max(ans,dp[i]);
	printf("%d",ans);
	return 0;
}