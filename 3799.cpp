#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct node{int l,r;}tmp[100005],a[100005];
int n,m,f[100005][20]={{0},{0}},L,R;
inline bool cmp(const node &a,const node &b)
{return a.l<b.l||(a.l==b.l&&a.r>b.r);}
void ST()
{
    a[n+1].l=a[n+1].r=0x3f3f3f3f;
    f[n+1][0]=n+1;
    for(int i=1,j=1;i<=n;i++)
    {
        while(j<=n&&a[j].l<a[i].r) j++;
        f[i][0]=j;
    }
    for(int i=1;i<=log2(n)+1;i++)
        for(int j=1;j<=n+1;j++)
            f[j][i]=f[f[j][i-1]][i-1];
}
void Query()
{
    scanf("%d%d",&L,&R);
    int pos=0,l=1,r=n+1,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(a[mid].l>=L) pos=mid,r=mid-1;
        else l=mid+1;
    }
    int ans=0;
    for(int i=log2(n)+1;i>=0;i--)
        if(a[f[pos][i]].r<=R)
        {
            pos=f[pos][i];
            ans+=(1<<i);
        }
    printf("%d\n",ans+(a[pos].r<=R));
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&tmp[i].l,&tmp[i].r);
    sort(tmp+1,tmp+n+1,cmp);
    int top=0;
    for(int i=1;i<=n;i++)
    {
        while(top>0&&a[top].r>tmp[i].r) top--;
        a[++top]=tmp[i];
    }
    n=top;
    ST();
    for(int i=1;i<=m;i++) Query();
	return 0;
}
