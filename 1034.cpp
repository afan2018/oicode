#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct Point{int x,y;}P[705];
int n,ans=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&(P+i)->x,&(P+i)->y);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int tot=2;
            for(int k=j+1;k<=n;k++)
                if((P[i].x-P[k].x)*(P[j].y-P[k].y)-(P[i].y-P[k].y)*(P[j].x-P[k].x)==0)
                    tot++;
            ans=max(tot,ans);
        }
    printf("%d\n",ans);
    return 0;
}
