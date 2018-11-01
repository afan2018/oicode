#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct Point{int x,y;}P[1005];
struct node{int fr,to;double val;}edge[1000005];
int n,fa[1005]={0},sum=0,cnt=0;
double ans=0;
inline double Euclid(int x,int y)
{return sqrt((P[x].x-P[y].x)*(P[x].x-P[y].x)+(P[x].y-P[y].y)*(P[x].y-P[y].y));}
inline void Add(int x,int y,double z)
{edge[++sum].fr=x,edge[sum].to=y,edge[sum].val=z;}
inline bool cmp(const node &a,const node &b)
{return a.val<b.val;}
inline int Getfa(int x)
{return x==fa[x]?x:fa[x]=Getfa(fa[x]);}
void K()
{
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=sum;i++)
    {
        int fa1=Getfa(edge[i].fr);
        int fa2=Getfa(edge[i].to);
        if(fa1!=fa2)
        {
            fa[fa1]=fa2;
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
        scanf("%d%d",&P[i].x,&P[i].y);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            Add(i,j,Euclid(i,j));
    sort(edge+1,edge+sum+1,cmp);
    K();
    printf("%.2lf\n",ans);
    return 0;
}
