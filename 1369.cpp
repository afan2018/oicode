#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int sum[105]={0},rec[105][105]={0},dp[105][105]={0},n,k;
void Print(int a,int b)
{
    if(a==0) return;
    Print(a-1,rec[a][b]-1);
    cout<<rec[a][b]<<' '<<b<<endl;
}
int main()
{
    cin>>n>>k;
    for(int i=1,x;i<=n;i++)
        cin>>x,sum[i]=sum[i-1]+x;
    for(int i=1;i<=n;i++)
        dp[1][i]=sum[i],rec[1][i]=1;
    for(int i=0;i<=k;i++) dp[i][0]=0;
    for(int i=2;i<=k;i++)
        for(int j=1;j<=n-k+i;j++)
        {
            dp[i][j]=0x7f7f7f7f;
            for(int p=i;p<=j;p++)
            {
                int maxx=max(dp[i-1][p-1],sum[j]-sum[p-1]);
				if(dp[i][j]>maxx)
				{
					dp[i][j]=maxx;
					rec[i][j]=p;
				}
            }
        }
    cout<<dp[k][n]<<'\n';
    Print(k,n);
    return 0;
}
/*
9 3
1 2 3 4 5 6 7 8 9 
*/