#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{int t,ed,id;}a[55];
int T,n;
bool dp[105][505]={{0},{0}},need[105][105]={{0},{0}};
inline bool cmp(const node &a,const node &b)
{return a.t<b.t||(a.t==b.t&&a.ed==0);}
void DP()
{
    dp[0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<8);j++)
            if(dp[i][j])
                for(int k=1;k<9;k++)
                    if(need[a[i+1].id][k])
                    {
                        if((!a[i+1].ed)&&(!(j&(1<<(k-1))))) dp[i+1][j|(1<<(k-1))]=1;
                        if(a[i+1].ed&&(j&(1<<(k-1)))) dp[i+1][j-(1<<(k-1))]=1;
                    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        memset(need,0,sizeof(need));
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i=1,cnt;i<=n;i++)
        {
            a[2*i].id=a[2*i-1].id=i;
            scanf("%d%d%d",&a[2*i-1].t,&a[2*i].t,&cnt);
            a[2*i].ed=1,a[2*i-1].ed=0;
            for(int j=1,x;j<=cnt;j++)
            {
                scanf("%d",&x);
                need[i][x]=1;
            }
        }
        n*=2;
        sort(a+1,a+n+1,cmp);
        DP();
        (dp[n][0])?puts("YES"):puts("NO");
    }
    return 0;
}
