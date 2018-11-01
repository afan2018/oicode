#include<iostream>
using namespace std;
struct node{int time,val;}gra[105];
int f[105][1005]={0},ttime,n;
int main()
{
	cin>>ttime>>n;
	for(int i=1;i<=n;i++) cin>>gra[i].time>>gra[i].val;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=ttime;j++)
			if(j>=gra[i].time) f[i][j]=max(f[i-1][j],f[i-1][j-gra[i].time]+gra[i].val);
				else f[i][j]=f[i-1][j];
	int maxx=f[n][1];
	for(int i=ttime;i>=1;i--)
		maxx=max(maxx,f[n][i]);
	cout<<maxx<<'\n';
	return 0;
}
