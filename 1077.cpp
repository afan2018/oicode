#include<iostream>
using namespace std;
int main(){
	int n,val[105][105]={0},dis[105][105]={0};
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin>>val[i][j];
	for(int i=1;i<=n;i++)dis[n][i]=val[n][i];
	for(int i=n-1;i>0;i--)
		for(int j=1;j<=i;j++)
			dis[i][j]=val[i][j]+max(dis[i+1][j],dis[i+1][j+1]);
	cout<<dis[1][1];
	return 0;
}