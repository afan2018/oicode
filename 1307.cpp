#include<iostream>
using namespace std;
typedef long long ll;
ll map[105][105]={0},n,k;
int main()
{
    scanf("%lld%lld",&n,&k);
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
        {
            scanf("%lld",&map[i][j]);
            if(map[i][j]==-1) map[i][j]=0x3f3f3f3f;
        }
    for(ll kk=0;kk<n;kk++)
        for(ll i=0;i<n;i++)
            for(ll j=0;j<n;j++)
                if(map[i][kk]!=0x3f3f3f3f&&map[kk][j]!=0x3f3f3f3f)
                    map[i][j]=min(map[i][j],map[i][kk]+map[kk][j]);
    for(ll i=0;i<n;i++)
    {
        if(map[k][i]==0x3f3f3f3f) printf("-1 ");
        else printf("%lld ",map[k][i]);
    }
    return 0;
}
