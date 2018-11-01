#include<iostream>
#include<cstring>
using namespace std;
int n,m,k,seq[10005]={0},dp[10005][105]={{0},{0}};
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    memset(dp,0xcf,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",seq+i);
        dp[i][1]=max(dp[i-1][1],seq[i]);
    }
    for(int i=k;i<=n;i++)
        for(int j=2;j<=m;j++)
            dp[i][j]=max(dp[i-1][j],dp[i-k][j-1]+seq[i]);
    printf("%d\n",dp[n][m]);
    return 0;
}
