#include<iostream>
#define dogliu int
using namespace std;
int main(){
	dogliu map[15][15]={0},n,m,mov[15][15][15][15]={0};
	cin>>n;
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		if(a+b+c==0)break;
		map[a][b]=c;
	}
	for(int x1=1;x1<=n;x1++)
		for(int y1=1;y1<=n;y1++)
			for(int x2=1;x2<=n;x2++)
				for(int y2=1;y2<=n;y2++)
				{
					mov[x1][y1][x2][y2]=mov[x1-1][y1][x2-1][y2];
					mov[x1][y1][x2][y2]=max(mov[x1][y1][x2][y2],mov[x1-1][y1][x2][y2-1]);
					mov[x1][y1][x2][y2]=max(mov[x1][y1][x2][y2],mov[x1][y1-1][x2-1][y2]);
					mov[x1][y1][x2][y2]=max(mov[x1][y1][x2][y2],mov[x1][y1-1][x2][y2-1]);
					mov[x1][y1][x2][y2]+=(map[x1][y1]+map[x2][y2]);
					if(x2==x1&&y1==y2) mov[x1][y1][x2][y2]-=map[x1][y1];
				}
	cout<<mov[n][n][n][n];
	return 0;
}
/*
8
2 3 13
2 6 6
3 5 7
4 4 14
5 2 21
5 6 4
6 3 15
7 2 14
0 0 0
*/