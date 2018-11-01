#include<iostream>
#include<cstring>
using namespace std;
int st,ed,m,dis[105][105]={0},val[10]={0,2,6,4,8,6,10,14},map[105]={0},cnt=0,ha[105]={0};
int main()
{
    for(int i=1,x;i<=7;i++)
    {
        scanf("%d",&x);
        if(x) val[i]/=2;
    }
    scanf("%d%d%d",&st,&ed,&m);
    memset(dis,0x7f,sizeof(dis));
    for(int i=1,x,y,z;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(!ha[x])
        {
            ha[x]=++cnt;
            map[cnt]=x;
        }
        if(!ha[y])
        {
            ha[y]=++cnt;
            map[cnt]=y;
        }
        dis[x][y]=val[z];
        dis[y][x]=val[z];
    }
    for(int i=1;i<=cnt;i++)
        dis[map[ha[i]]][map[ha[i]]]=0;
    for(int k=1;k<=cnt;k++)
        for(int i=1;i<=cnt;i++)
            for(int j=1;j<=cnt;j++)
                if(dis[map[i]][map[k]]!=0x7f7f7f7f&&dis[map[k]][map[j]]!=0x7f7f7f7f)
                    dis[map[i]][map[j]]=min(dis[map[i]][map[j]],dis[map[i]][map[k]]+dis[map[k]][map[j]]);
    printf("%d",dis[st][ed]);
    return 0;
}