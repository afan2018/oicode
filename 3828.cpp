#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,dp[100005][2]={0},seq[100005]={0}; //1 up 0 down . 
int main()
{
	scanf("%d",&n);
	if(n==1) {puts("1");return 0;}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",seq+i);
		dp[i][1]=1;
		dp[i][0]=1;
	}
	for(int i=2;i<=n;i++)
		for(int j=i-1;j>0;j--)
		{
			if(seq[j]<seq[i]) dp[i][1]=max(dp[j][0]+1,dp[i][1]);//end with i && go up .
			if(seq[j]>seq[i]) dp[i][0]=max(dp[j][1]+1,dp[i][0]);//end with i && go down .
			if(dp[i][0]!=1&&dp[i][1]!=1) break;//找到在我前面的首个up和down拐点就完了，由于越后面越优，所以倒着做。 
		}
	printf("%d",max(dp[n][0],dp[n][1]));//由于上面的保证n就是存了最优答案。 
	return 0;
}