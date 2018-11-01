#include<iostream>
#include<algorithm>
using namespace std;
struct node{int fr,to,val;}edge[300005];
int n,fa[305]={0},cnt=0,val[305][305];
bool cmp(const node &a,const node &b)
{return a.val<b.val;}
int G(int x)
{return fa[x]==x?x:fa[x]=G(fa[x]);}
void K()
{
    int ccnt=0,ans=0;
    for(int i=0;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=cnt;i++)
    {
        int fa1=G(edge[i].fr);
        int fa2=G(edge[i].to);
        if(fa1!=fa2)
        {
            fa[fa1]=fa2;
            ans+=edge[i].val;
            ccnt++;
        }
        if(ccnt==cnt-1) break;
    }
    cout<<ans;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>edge[i].val;
        edge[i].fr=i;
        edge[i].to=0;
    }
    cnt=n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>val[i][j];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            edge[++cnt].to=j;
            edge[cnt].fr=i;
            edge[cnt].val=val[i][j];
        }
    sort(edge+1,edge+cnt+1,cmp);
    K();
    return 0;
}
