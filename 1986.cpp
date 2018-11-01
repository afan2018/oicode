#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct node{int val,pos;}Q[50005];
int n,T,seq[50005]={0},dp[50005]={0};
bool Check(int x)
{
	memset(dp,0x3f,sizeof(dp));
	int L=1,R=0;
	dp[0]=0;
	Q[++R].pos=Q[R].val=0;
	for(int i=1;i<=n;i++)
	{
		while(L<=R&&Q[L].pos<i-x-1) L++;
		dp[i]=min(dp[i],Q[L].val+seq[i]);
		while(L<=R&&Q[R].val>dp[i]) R--;
		Q[++R].val=dp[i],Q[R].pos=i;
	}
	for(int i=n-x;i<=n;i++)
		if(dp[i]<=T) return true;
	return false;
}
int BS()
{
	int L=0,R=n,mid,ans=-1;
	while(L<=R)
	{
		mid=(L+R)/2;
		if(Check(mid)) ans=mid,R=mid-1;
		else L=mid+1;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++) scanf("%d",seq+i);
	printf("%d",BS());
	return 0;
}
