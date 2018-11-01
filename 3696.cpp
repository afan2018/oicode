#include<iostream>
using namespace std;
struct node{int to,nx;}edge[200005]={0};
int dp[100005][25]={0},n,k,h[100005]={0},cnt=0;
void Add(int a,int b)
{edge[++cnt].to=b,edge[cnt].nx=h[a],h[a]=cnt;}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1,x,y;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        Add(x,y);
        Add(y,x);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&dp[i][0]);
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==1) dp[j][i]=dp[j][i-1];
            else dp[j][i]=dp[j][i-2];
            for(int l=h[j];l;l=edge[l].nx)
            {
                int to=edge[l].to;
                dp[j][i]+=dp[to][i-1];
                if(i!=1)
                dp[j][i]-=dp[j][i-2];
            }
        }
    for(int i=1;i<=n;i++)
        printf("%d\n",dp[i][k]);
    return 0;
}
