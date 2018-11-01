#include<iostream>
#include<algorithm>
using namespace std;
int fa[100005]={0},n,m;
struct node{int a,b,val;}unh[100005];
inline bool cmp(const node &a,const node &b)
{return a.val>b.val;}
int GetFa(int x)
{return fa[x]==x?x:fa[x]=GetFa(fa[x]);}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&unh[i].a,&unh[i].b,&unh[i].val);
    for(int i=1;i<=2*n;i++)
        fa[i]=i;
    sort(unh+1,unh+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        int f1=GetFa(unh[i].a);
        int f2=GetFa(unh[i].b);
        if(f1==f2)
        {
            printf("%d\n",unh[i].val);
            return 0;
        }
        fa[f1]=GetFa(unh[i].b+n);
        fa[f2]=GetFa(unh[i].a+n);
    }
    printf("%d\n",0);
    return 0;
}
