#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int const maxx=0x3f3f3f3f;
bool judge=false;
int n,vis[1003]={0},m,s,map[1002][1002]={0},dis[1003],cnt=0,out=-1,k=0;
struct node{int p,q;}chan[100001]={0};
bool bell()
{
	for(int i=1;i<=n;i++)dis[i]=maxx;
	dis[s]=0;
	for(int i=1;i<=n;i++)
	{
		int x1,y1;
		bool judge=false;
	   for(int i=1;i<=m;i++)
        {
        	x1=chan[i].p;
        	y1=chan[i].q;
		if(dis[x1]!=maxx&&map[x1][y1]!=maxx&&dis[x1]+map[x1][y1]<dis[y1])
          {
		   judge=true;
           dis[y1]=dis[x1]+map[x1][y1];
           vis[y1]++;
           if(vis[y1]>n)return 0;
          }
		}
         
        if(!judge) return 1;  
	}	
	return 0;
	
}
int main()
{
    int x,y,c;
	scanf("%d%d%d",&n,&m,&s);
	memset(map,0x3f,sizeof(map));
	for(int i=1;i<=m;i++)
	{
	  scanf("%d%d%d",&x,&y,&c);
	  map[x][y]=min(map[x][y],c);
	  chan[i].p=x;
	  chan[i].q=y;
	}
	if(bell())
	 {
	 	for(int i=1;i<=n;i++)
     	     if(dis[i]!=maxx) cout<<dis[i]<<endl;
	                     else cout<<"NoPath"<<endl;
    }
    else cout<<-1;
	return 0;
}