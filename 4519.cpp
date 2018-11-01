#include<iostream>
#include<cstring>
using namespace std;
int T,n,pok[15]={0},ans=0;
int Calc(int pok[])
{
    int cnt[15]={0},ret=0;
    for(int i=0;i<=13;i++) cnt[pok[i]]++;
    while(cnt[4]&&cnt[2]>=2) cnt[4]--,cnt[2]-=2,ret++;
    while(cnt[4]&&cnt[1]>=2) cnt[4]--,cnt[1]-=2,ret++;
    while(cnt[3]&&cnt[2]>=1) cnt[3]--,cnt[2]--,ret++;
    while(cnt[3]&&cnt[1]>=1) cnt[3]--,cnt[1]--,ret++;
    return ret+cnt[4]+cnt[3]+cnt[2]+cnt[1];
}
void DFS(int dep)
{
    if(dep>ans) return;
    ans=min(ans,dep+Calc(pok));
    for(int i=2;i<=13;i++)
    {
        int j=i;
        while(pok[j]>2) j++;
        if(j-i>1)
        {
        	for(int t=i+1;t<j;t++)
        	{
        		for(int k=i;k<=t;k++) pok[k]-=3;
           	 	DFS(dep+1);
            	for(int k=i;k<=t;k++) pok[k]+=3;
			}
    	}
	}
    for(int i=2;i<=13;i++)
    {
        int j=i;
        while(pok[j]>1) j++;
        if(j-i>2)
        {
        	for(int t=i+2;t<j;t++)
        	{
        		for(int k=i;k<=t;k++) pok[k]-=2;
           	 	DFS(dep+1);
            	for(int k=i;k<=t;k++) pok[k]+=2;
			}
    	}
	}
   	for(int i=2;i<=13;i++)
    {
        int j=i;
        while(pok[j]) j++;
        if(j-i>4)
        {
        	for(int t=i+4;t<j;t++)
        	{
        		for(int k=i;k<=t;k++) pok[k]--;
           	 	DFS(dep+1);
            	for(int k=i;k<=t;k++) pok[k]++;
			}
    	}
	}
}
int main()
{
    scanf("%d%d",&T,&n);
    while(T--)
    {
        ans=0;
        memset(pok,0,sizeof(pok));
        for(int i=1,x,y;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            if(x==1) x=13;
            else if(x) x--;
            pok[x]++;
        }
        ans=Calc(pok);
        DFS(0);
        printf("%d\n",ans);
    }
    return 0;
}