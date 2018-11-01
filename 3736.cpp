#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
struct node{ll fr,to;}con[1000005];
ll c[30005]={0},n,m,k,t,cnt=0;
inline bool cmp(const node &a,const node &b)
{return a.fr<b.fr||(a.fr==b.fr&&a.to<b.to);}
inline ll Lowbit(ll x)
{return x&(-x);}
ll Sum(ll x)
{
    ll ret=0;
    for(ll i=x;i;i-=Lowbit(i))
        ret+=c[i];
    return ret;
}
void Insert(ll x)
{
    for(ll i=x;i<=m;i+=Lowbit(i))
        c[i]++;
}
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&m,&k);
        for(ll i=1;i<=k;i++)
            scanf("%lld%lld",&con[i].fr,&con[i].to);
        sort(con+1,con+k+1,cmp);
        ll ans=0;
        for(ll i=k;i;i--)
        {
            ans+=Sum(con[i].to-1);
            Insert(con[i].to);
        }
        cnt++;
        printf("Test case %lld: %lld\n",cnt,ans);
        memset(con,0,sizeof(con));
        memset(c,0,sizeof(c));
    }
    return 0;
}
