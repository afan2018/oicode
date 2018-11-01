#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
struct node{int fr,to;double val;}edge[2000005];
struct point{int x,y;}p[1005];
int n,m,fa[1005]={0},map[1005][1005]={0},cnt=0;
double Euclid(int x,int y)
{return sqrt((long long)(p[x].x-p[y].x)*(p[x].x-p[y].x)+(long long)(p[x].y-p[y].y)*(p[x].y-p[y].y));}
inline bool cmp(const node &a,const node &b)
{return a.val<b.val;}
int Getfa(int x)
{return fa[x]==x?x:fa[x]=Getfa(fa[x]);}
void Kruskal()
{
    int ccnt=0;
    double ans=0;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=cnt;i++)
    {
        int fa1=Getfa(edge[i].fr);
        int fa2=Getfa(edge[i].to);
        if(fa1!=fa2)
        {
            fa[fa1]=fa2;
            ccnt++;
            ans+=edge[i].val;
        }
        if(ccnt==n-1) break;
    }
    cout<<fixed<<setprecision(2)<<ans<<'\n';
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>p[i].x>>p[i].y;
    for(int i=1;i<=m;i++)
    {
        cin>>edge[i].fr>>edge[i].to;
        map[edge[i].fr][edge[i].to]=1;
        map[edge[i].to][edge[i].fr]=1;
        edge[i].val=0;
    }
    cnt=m;
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(map[i][j]) continue;
            edge[++cnt].fr=i;
            edge[cnt].to=j;
            edge[cnt].val=Euclid(edge[cnt].fr,edge[cnt].to);
        }
    sort(edge+1,edge+cnt+1,cmp);
    Kruskal();
    return 0;
}