#include<iostream>
#include<algorithm>
using namespace std;
struct node{int fr,to,val;}edge[20005]={0};
int n,m,sum,fa[20005]={0},ans=0;
bool cmp(const node &a,const node &b)
{return a.val<b.val;}
int G(int x)
{return fa[x]==x?x:fa[x]=G(fa[x]);}
void K()
{
    int cnt=0;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int fa1=G(edge[i].fr);
        int fa2=G(edge[i].to);
        if(fa1!=fa2)
        {
            fa[fa1]=fa2;
            ans+=edge[i].val;
            cnt++;
        }
        if(cnt==n-1) break;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1,a,b,c;i<=m;i++)
    {
        cin>>a>>b>>c;
        //if(c==0) continue;
        edge[i].fr=a;
        edge[i].to=b;
        edge[i].val=c;
        sum+=edge[i].val;
    }
    sort(edge+1,edge+m+1,cmp);
    K();
    cout<<sum-ans;
    return 0;
}
