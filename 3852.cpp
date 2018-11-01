#include<iostream>
#include<cstdio>
using namespace std;
int Map[505][505];
bool book[505][505];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int T[100000];
struct node{
	int x;
	int y;
	int step;
}Q[6000000];
int main(){
	int n,m,a,b,p;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	p=b;
	for(int i=0;i<a;i++){
		scanf("%d%d",&Q[i].x,&Q[i].y);
		Q[i].step=0;
		book[Q[i].x][Q[i].y]=1;
	}
	for(int i=1;i<=b;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		Map[x][y]=i;
	}
	int l=0;
	int r=a-1;
	while(l<=r){
		int x=Q[l].x;
		int y=Q[l].y;
		for(int i=0;i<=3;i++){
			bool flag=0;
			int tx=x+dx[i];
			int ty=y+dy[i];
			if(tx<=0||tx>=n+1||ty<=0||ty>=m+1)continue;
			if(!book[tx][ty]){
				r++;
				book[tx][ty]=1;
				Q[r].x=tx;
				Q[r].y=ty;
				Q[r].step=Q[l].step+1;
				if(Map[tx][ty]){
					b--;
					T[Map[tx][ty]]=Q[r].step;
					if(b==0){
						flag=1;
						break;
					}
				}
			}
			if(flag)break;
		}
		l++;
	}
	for(int i=1;i<=p;i++)printf("%d\n",T[i]);
	return 0;
}