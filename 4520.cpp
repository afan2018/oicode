#include<cstdio>
int L,N,M,seq[50005]={0};
bool Check(int x)
{
    int pos=0,sum=0;
    for(int i=1;i<=N;i++)
        if(seq[i]-pos<x) sum++;
        else pos=seq[i];
    return (sum<=M);
}
int main()
{
    scanf("%d%d%d",&L,&N,&M);
    int l=0,r=L,mid,ans=0;
    for(int i=1;i<=N;i++) scanf("%d",seq+i);
    while(l<=r)
    {
        mid=(l+r)/2;
        if(Check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}
