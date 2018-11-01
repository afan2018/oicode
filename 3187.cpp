#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{int sco,val,num;}com[1000005],win[1000005],lose[1000005],tmp[1000005];
int n,r,q;
inline bool cmp(const node &a,const node &b)
{return a.sco>b.sco||(a.sco==b.sco&&a.num<b.num);}
int main()
{
    cin>>n>>r>>q;
    for(int i=1;i<=2*n;i++)
    {
        cin>>com[i].sco;
        com[i].num=i;
    }
    for(int i=1;i<=2*n;i++)
        cin>>com[i].val;
    sort(com+1,com+2*n+1,cmp);
    while(r--)
    {
        int topw=0,topl=0;
        for(int i=1;i<=2*n;i++)
        {
            if(i%2==0) continue;
            win[++topw]=com[i].val>com[i+1].val?com[i]:com[i+1];
            lose[++topl]=com[i].val>com[i+1].val?com[i+1]:com[i];
            win[topw].sco++;
        }
        int l=1,r=1,cnt=0;
        while(l<=topw&&r<=topl)
        {
            if(cmp(win[l],lose[r]))
                tmp[++cnt]=win[l++];
            else tmp[++cnt]=lose[r++];
        }
        while(l<=topw) tmp[++cnt]=win[l++];
        while(r<=topl) tmp[++cnt]=lose[r++];
        memcpy(com,tmp,sizeof(tmp));
    }
    cout<<com[q].num;
    return 0;
}