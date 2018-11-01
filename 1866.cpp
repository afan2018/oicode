#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int pho[185][185]={0},n,m,ans[185][185]={0},vis[185][185]={0},newx,newy;
int dirx[4]={1,-1,0,0},diry[4]={0,0,1,-1};
struct node{int x,y,dis;}quene[100005];
int abs(int a,int b)
{
	if(a>b)return a-b;
	else return b-a;
}
void init()
{
	cin>>n>>m;
	char ch;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			ch=getchar();
			if(ch=='\n') j--;
			if(ch=='0')pho[i][j]=0;
			if(ch=='1')pho[i][j]=1;
		}
}
void BMP()
{
	memset(quene,0,sizeof(quene));
	memset(vis,0,sizeof(vis));
	int head=1,tail=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(pho[i][j]){
				quene[++tail].x=i;
				quene[tail].y=j;
				quene[tail].dis=0;
				vis[i][j]=1;
			}
	while(head<=tail)
	{
		for(int i=0;i<=3;i++)
		{
			
			newx=quene[head].x+dirx[i];
			newy=quene[head].y+diry[i];
			if(newx<=0||newx>n||newy<=0||newy>m) continue;
			if(!vis[newx][newy])
			{
				tail++;
				quene[tail].x=newx;
				quene[tail].y=newy;
				quene[tail].dis=quene[head].dis+1;
				ans[newx][newy]=quene[tail].dis;
				vis[newx][newy]=1;
			}
		}
		head++;
	}
}
void print()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout<<ans[i][j]<<' ';	
		cout<<endl;
	}
}
int main(){
	init();
	BMP();
	print();
	return 0;
}