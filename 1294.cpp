#include<iostream>
#include<cstring>
using namespace std;
int n,a[50][50],work[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
int main(){
	cin>>n;
	memset(a,-1,sizeof(a));
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=1;j<=n;j++)
		a[i][j]=0;
	  }
	int i=0,dir=0,x=0,y=n,newx,newy;
	while(i<n*n){
		newx=x+work[dir][0];
		newy=y+work[dir][1];
		if(a[newx][newy]==0)
		{
			x=newx;
			y=newy;
			a[x][y]=i+1;
			i++;
		}
		else dir=(dir+1)%4;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)cout<<a[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}