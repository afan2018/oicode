#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node{ll l,r;}edge[100005];
ll n,m,k,vl[40005]={0},vr[40005]={0},dpl[40005]={0},dpr[40005]={0},ansl=0,ansr=0,maxx=0;
inline bool cmp(const node &a,const node &b)
{return a.l<b.l||(a.l==b.l&&a.r<b.r);}
int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&vl[i]),dpl[i]=vl[i];
    for(ll i=1;i<=m;i++)
        scanf("%lld",&vr[i]),dpr[i]=vr[i];
    for(ll i=1,x,y;i<=k;i++)
        scanf("%lld%lld",&edge[i].l,&edge[i].r);
    sort(edge+1,edge+k+1,cmp);
    for(ll i=1;i<=k;i++)
    {
        ll tmpl=dpl[edge[i].l];
        ll tmpr=dpr[edge[i].r];
        dpl[edge[i].l]=max(dpl[edge[i].l],tmpr+vl[edge[i].l]);
        dpr[edge[i].r]=max(dpr[edge[i].r],tmpl+vr[edge[i].r]);
    }
    for(int i=1;i<=n;i++)
        maxx=max(maxx,dpl[i]);
    for(int i=1;i<=m;i++)
        maxx=max(maxx,dpr[i]);
    printf("%lld",maxx);
    return 0;
}
