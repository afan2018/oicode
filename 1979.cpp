#include<iostream>
using namespace std;
int seq[300005]={0},n,ans,top,dig[35]={0};
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&seq[i]);
    top=n;
    for(int i=30;i>=0;i--)
    {
        int cnt=0;
        for(int j=1;j<=top;j++)
            if(seq[j]&(1<<i))
                cnt++;
        if(cnt<2) continue;
        dig[i]=1;
        int ntop=0;
        for(int j=1;j<=top;j++)
            if(seq[j]&(1<<i))
                seq[++ntop]=seq[j];
        top=ntop;
    }
    for(int i=0;i<=30;i++)
        if(dig[i])
            ans+=(1<<i);
    printf("%d",ans);
    return 0;
}
