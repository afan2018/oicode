#include<cstdio>
#include<iostream>
int seq[100005]={0},n,dp[100005]={0},ans,S[100005]={0},top=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&seq[i]),seq[i]-=i;
	for(int i=1;i<=n;i++)
	{
		if(seq[i]>=S[top]) S[++top]=seq[i];
		else *(std::lower_bound(S+1,S+top+1,seq[i]))=seq[i];
	}
	printf("%d",n-top);
	return 0;
}
