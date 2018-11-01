#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxx=0x3f3f3f3f;
int n,m,map[5005][5005]={0},q[100001]={0},dis[5005],s[5005]={0},vis[100001]={0};
void spfa()
{
	int op=0,ed=1,cc;
	q[1]=1;
	vis[1]=1;
	for(int i=1;i<=n;i++)dis[i]=maxx;
	dis[1]=0;
	while(op!=ed)
	{
	  op=(op+1)%5005;
	  cc=q[op];
      s[cc]=0;
      for(int j=1;j<=n;j++)
      {  
	     if(map[cc][j]!=0&&dis[j]>dis[cc]+map[cc][j])
         {  vis[j]++;
            if(vis[j]>=n) return;
            dis[j]=dis[cc]+map[cc][j]; 
            if(s[j]==0){ed=(ed+1)%5005;q[ed]=j;s[j]=1;}
         }
     }
   }
   return;	
}
int main()
{
    int x,y,c;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)	{scanf("%d%d%d",&x,&y,&c);map[x][y]=c;}
	spfa();
	cout<<dis[n];
	return 0;
}