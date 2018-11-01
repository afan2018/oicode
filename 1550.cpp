#include<iostream>
using namespace std;
int main(){
	int n,map[25][25]={0},x,y,fl=1;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>map[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			fl=1;
			for(int k=1;k<=n;k++)
				if(map[i][k]<map[i][j]){fl=0;break;}
			for(int k=1;k<=n;k++)
				if(map[k][j]>map[i][j]){fl=0;break;}
			if(fl){cout<<"("<<i<<","<<j<<")";break;}
		}
	return 0;
}
/*
5
5 6 7 8 9
4 5 6 7 8
3 4 5 2 1
2 3 4 9 0
1 2 5 4 8
*/