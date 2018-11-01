#include<iostream>
using namespace std;
bool vis[100000]={0};
int a[100000]={0};
int k;
int n=1;
bool finish=0;
bool ck(){
     for(int i=n-k+2;i<=n-1;i++)
       {
        int s=0;     
         for(int j=i;j<=i+k-1;j++)
           s=s*2+a[j];
         if(vis[s])
           return false;
         vis[s]=true;
        }
       return true;
     }
void dfs(int h){
     if(finish)
       return;
     if(h==n+1)
       {
       if(ck())
        {
         for(int i=1;i<=n-1;i++)
           printf("%d",a[i]);
         printf("1");
         }
       finish=1;
       return;
       }
       int t=0;
       a[h]=0;
     for(int i=h-k+1;i<=h;i++)
       t=t*2+a[i];
     if(!vis[t])
       {
        vis[t]=true;
        dfs(h+1);
        vis[t]=false;        
        }
       a[h]=1;
       t++;
     if(!vis[t])
       {
        vis[t]=true;
        dfs(h+1);
        vis[t]=false;        
        }
     }
int main(){
scanf("%d",&k);
for(int i=1;i<=k;i++)
  n*=2;
printf("%d ",n);
for(int i=n+1;i<=n+k;i++)
  a[i]=0;
for(int i=1;i<=k;i++)
  a[i]=0;
  vis[0]=true;
dfs(k+1);
getchar();getchar();
return 0;
}