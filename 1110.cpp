#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[101][101]={0},v[101][101]={0},x1,x2,y1,y2;
int y,x;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
struct node{int x,y,c;}q[100000];
void sc()
{   memset(a,0,sizeof(a));
	char c;
	scanf("%d%d",&y,&x);c=getchar();
	for(int i=1;i<=x;i++)
	   for(int j=1;j<=y+1;j++){c=getchar();if(c=='X')a[i][j]=1;}
}
int BFS(int x1,int y1)
{
	int st=1,ed=1,X,Y;
	memset(q,0,sizeof(q));
	memset(v,0,sizeof(v));
	q[1].x=x1;q[1].y=y1;q[1].c=0;
	v[x1][y1]=1;
	while(st<=ed)
	{
		for(int i=0;i<=3;i++)
			for(int j=1;;j++)
			{
				X=q[st].x+dx[i]*j;
				Y=q[st].y+dy[i]*j;
				if(X==x2&&Y==y2){cout<<q[st].c+1<<endl;return 1;}
				if(X<0||Y<0||X>x+1||Y>y+1||a[X][Y])break;
				if(!v[X][Y])
				{
					ed++;q[ed].x=X;q[ed].y=Y;q[ed].c=q[st].c+1;
					v[X][Y]=1;
				}
			}
		
		st++;
	}
	return 0;
}
int main(){
	sc();
	while(1)
	{
		scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
		if(x1==0&&y1==0&&x2==0&&y2==0)break;
		if(!BFS(x1,y1))printf("%d\n",0);
	}
	return 0;
}