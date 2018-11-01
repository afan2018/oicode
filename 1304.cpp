#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{int fr,to;double val;}edge[1000005];
struct point{int x,y;}p[1005];
int n,sum=0,fa[1005]={0},cnt=0;
double ans=0;
inline double Euclid(point a,point b)
{return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
inline bool cmp(const node &a,const node &b)
{return a.val<b.val;}
inline int Getfa(int x)
{return fa[x]==x?x:fa[x]=Getfa(fa[x]);}
void Kruskal()
{
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=sum;i++)
    {
        int fa1=Getfa(edge[i].fr);
        int fa2=Getfa(edge[i].to);
        if(fa1!=fa2)
        {
            fa1=fa2;
            cnt++;
            ans+=edge[i].val;
            if(cnt==n-1) break;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            edge[++sum].fr=i;
            edge[sum].to=j;
            edge[sum].val=Euclid(p[i],p[j]);
        }
    sort(edge+1,edge+sum+1,cmp);
    Kruskal();
    printf("%.2lf",ans);
    return 0;
}
