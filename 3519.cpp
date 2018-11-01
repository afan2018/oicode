#include<iostream>
#include<algorithm>
using namespace std;
struct node{int r,d,id;}a[100005];
int n,group[100005]={0},maxr[100005]={0},now=0;
inline bool cmp(const node &a,const node &b)
{return a.d>b.d;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].d,&a[i].r),a[i].id=i;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        maxr[now+1]=0;
        int l=1,r=now+1,mid;
        while(l<r)
        {
            mid=(l+r)/2;
            if(maxr[mid]>a[i].r) l=mid+1;
            else r=mid;
        }
        maxr[r]=a[i].r;
        group[a[i].id]=r;
        if(r==now+1) now++;
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",group[i]);
    return 0;
}
