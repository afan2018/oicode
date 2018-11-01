#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int dp[20005]={0},val[20005]={0},cnt[20005]={0},idx,n,m,k;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",val+i);
	for(int i=1;i<=n;i++) scanf("%d",cnt+i);
	scanf("%d",&k);
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]>=k/val[i])
		{
			for(int j=val[i];j<=k;j++)
				dp[j]=min(dp[j],dp[j-val[i]]+1);
			continue;
		}
		idx=1;
		while(idx<cnt[i])
		{
			for(int j=k;j>=val[i]*idx;j--)
				dp[j]=min(dp[j],dp[j-val[i]*idx]+idx);
			cnt[i]-=idx;
			idx<<=1;
		}
		for(int j=k;j>=val[i]*cnt[i];j--)
			dp[j]=min(dp[j],dp[j-val[i]*cnt[i]]+cnt[i]);
	}
	printf("%d",dp[k]);
	return 0;
}
