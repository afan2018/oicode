#include<iostream>
#include<iomanip>
using namespace std;
double mat[105][105]={0},ans[105]={0};
int n;
double abs(double num)
{return num>0?num:-num;}
void Init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n+1;j++)
			cin>>mat[i][j];
}
void Deal(int x)
{
	int trans=x;
	double idx=0,maxx=abs(mat[x][x]);
	for(int i=x+1;i<=n;i++)
		if(abs(mat[i][x])>maxx)
			maxx=abs(mat[i][x]),trans=i;
	if(trans!=x) for(int i=x;i<=n+1;i++) swap(mat[x][i],mat[trans][i]);
	for(int i=x+1;i<=n;i++)
	{
		idx=mat[i][x]*1.0/mat[x][x];
		for(int j=x;j<=n+1;j++)
			mat[i][j]-=mat[x][j]*idx;
	}
}
void Gauss()
{
	for(int i=1;i<=n;i++) Deal(i);
	for(int i=n;i>0;i--)
	{
		for(int j=n;j>i;j--)
			mat[i][n+1]-=mat[i][j]*ans[j];
		ans[i]=mat[i][n+1]*1.0/mat[i][i];
	}
	for(int i=1;i<=n;i++)
		cout<<int(ans[i]+0.5)<<' ';
}
int main()
{
	Init();
	Gauss();
	return 0;
}
/*
2
1 1 3
1 -1 1
*/