#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node{ll x,y;}poll[10005],mid[1000005];
ll n,ha[1000005]={0},sum=0,ans=0,tot=1;
inline bool cmp(const node &a,const node &b)
{return a.x<b.x||(a.x==b.x&&a.y<b.y);}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld%lld",&poll[i].x,&poll[i].y);
    for(ll i=1;i<=n;i++)
        for(ll j=i+1;j<=n;j++)
        {
            mid[++sum].x=poll[i].x+poll[j].x;
            mid[sum].y=poll[i].y+poll[j].y;
        }
    sort(mid+1,mid+sum+1,cmp);
    ha[tot]=1;
    for(ll i=1;i<=sum;i++)
    {
        if(mid[i].x==mid[i+1].x&&mid[i].y==mid[i+1].y)
            ha[tot]++;
        else ha[++tot]=1;
    }
    for(ll i=1;i<=tot;i++)
        ans+=1ll*ha[i]*(ha[i]-1)/2;
    printf("%lld",ans);
    return 0;
}