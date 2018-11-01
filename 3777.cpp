#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
struct node{ll l,r,sum;}seg[300005];
ll n,m;
void Pushup(ll num)
{seg[num].sum=seg[num*2].sum+seg[2*num+1].sum;}
void Build(ll l,ll r,ll num)
{
    seg[num].l=l;
    seg[num].r=r;
    if(l==r)
    {
        scanf("%lld",&seg[num].sum);
        return;
    }
    ll mid=(l+r)/2;
    Build(l,mid,2*num);
    Build(mid+1,r,2*num+1);
    Pushup(num);
}
void Modify(ll l,ll r,ll num)
{
    if(l>seg[num].r||r<seg[num].l||seg[num].sum==(seg[num].r-seg[num].l+1)) return;
    if(seg[num].l==seg[num].r)
    {
        seg[num].sum=sqrt(seg[num].sum);
        return;
    }
    Modify(l,r,2*num);
    Modify(l,r,2*num+1);
    Pushup(num);
}
ll Sum(ll l,ll r,ll num)
{
    if(l>seg[num].r||r<seg[num].l) return 0;
    if(l<=seg[num].l&&r>=seg[num].r) return seg[num].sum;
    return Sum(l,r,2*num)+Sum(l,r,2*num+1);
}
int main()
{
    scanf("%lld",&n);
    Build(1,n,1);
    scanf("%lld",&m);
    for(ll i=1,x,y;i<=m;i++)
    {
        scanf("%lld",&x);
        if(!x)
        {
            scanf("%lld%lld",&x,&y);
            Modify(x,y,1);
        }
        else
        {
            scanf("%lld%lld",&x,&y);
            printf("%lld\n",Sum(x,y,1));
        }
    }
    return 0;
}
