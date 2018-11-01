#include<iostream>
#define dogliu int
using namespace std;
dogliu map[25][25]={0},n,mov[25][25][25][55]={0};
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>map[i][j];
	for(int k=1;k<=n+n;k++)
		for(int x1=1;x1<=min(k,n);x1++)
			for(int x2=1;x2<=min(k,n);x2++)
				for(int x3=1;x3<=min(k,n);x3++)
				{
					for(int i=-1;i<=0;i++)
						for(int j=-1;j<=0;j++)
							for(int kk=-1;kk<=0;kk++)
								mov[x1][x2][x3][k]=max(mov[x1][x2][x3][k],mov[x1+i][x2+j][x3+kk][k-1]);
					mov[x1][x2][x3][k]+=(map[x1][k-x1]+map[x2][k-x2]+map[x3][k-x3]);
					if(x2==x1&&x2==x3) 	{mov[x1][x2][x3][k]-=2*map[x1][k-x1];continue;}
					if(x2==x1) mov[x1][x2][x3][k]-=map[x1][k-x1];
					if(x2==x3) mov[x1][x2][x3][k]-=map[x2][k-x2];
					if(x1==x3) mov[x1][x2][x3][k]-=map[x1][k-x1];
				}
	cout<<mov[n][n][n][n+n];
	return 0;
}
/*
4
1 2 3 4
2 1 3 4
1 2 3 4
1 3 2 4
					
*/