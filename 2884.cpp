#include<iostream>
#include<cstring>
using namespace std;
#define maxn 1005 
#define INF 0x7fffffff
int cnt=0,n,d[maxn]={0},d1[maxn]={0},vst[maxn]={0},a[maxn][maxn]={0},q[maxn]={0};
int SPFA(int v0)
{      
    int L=0,r=0,i,j;
    for(i=1;i<=n;i++)d[i]=INF;
    d[v0]=0;
    r++;q[r]=v0;vst[v0]=1;
    while(L!=r)
	{
       L=(L+1)%maxn;
       i=q[L];vst[i]=0;
       for(j=1;j<=n;j++)
         if((a[i][j]!=0)&&(d[j]>d[i]+a[i][j]))
         {
            d[j]=d[i]+a[i][j];
            if(!vst[j]){r=(r+1)%maxn;q[r]=j;vst[j]=1;}
         }
	}
}
int SPFA1(int v0)
{
	int L=0,r=0,i,j,p;
    memset(vst,0,sizeof(vst));
    memset(q,0,sizeof(q));
    for(int i=1;i<=n;i++)d1[i]=INF;d1[v0]=0;
    r++;q[r]=v0;vst[v0]=1;
    while(L!=r)
	{
		L=(L+1)%maxn;
        i=q[L];vst[i]=0;
        for(int j=1;j<=n;j++)
          if((a[i][j]!=0)&&(d1[j]>d1[i]+a[i][j]))
          {
            d1[j]=d1[i]+a[i][j];
            if(!vst[j]){r=(r+1)%maxn;q[r]=j;vst[j]=1;}
          }
	}
}
int main()
{   
    int m,i,o,p,t,ans=INF,bj1,bj2,j;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
    	cin>>o>>p>>t;
        a[o][p]=t;
        a[p][o]=t;
    }
    SPFA(1);
    SPFA1(n);
    for(int i=1;i<=n;i++)
      for(int j=i+1;j<=n;j++)
        if(a[i][j])
        {
           if(ans>d[i]+d1[j]+a[i][j]/2)
           {
              ans=d[i]+d1[j]+a[i][j]/2;
              bj1=i;
              bj2=j;
           }
        }
    cout<<bj1<<" "<<bj2<<endl;
    cout<<ans;
    return 0;
}