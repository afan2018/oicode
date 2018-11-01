#include<iostream>
using namespace std;
int main(){
	int n,m,val[25][25]={0},gain[25][25]={0};
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>val[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<=j;k++)
				gain[i][j]=max(gain[i][j],gain[i-1][k]+val[i][j-k]);
	cout<<gain[n][m];
	return 0;
}
/*
4 3
1 2 3 4
2 1 4 3
3 1 4 2
*/