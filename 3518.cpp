#include<cstdio>
int n,s,ans;
long double maxx=0;
int Getint()
{
    int ret=0,fl=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')fl=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+(ch-'0'),ch=getchar();
    return fl*ret;
}
int main()
{
    n=Getint();
    s=Getint();
    for(int i=1;i<=n;i++)
    {
        int x,y;
        x=Getint();
        y=Getint();
        if((long double)(x)/y>maxx&&y<=s)
        {
            maxx=(long double)(x)/y;
            ans=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}
