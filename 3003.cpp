#include<iostream>
const int INF=0x7f7f7f7f;
using namespace std;
int f[2005][1005]={0},seq[1005][2005]={0},n,m,ans;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>seq[i][j];
	for(int i=1;i<=m;i++) f[0][i]=0;
	for(int i=1;i<=n;i++)
	{
		f[i][1]=min(f[i-1][m],f[i-1][1])+seq[1][i];
		for(int j=2;j<=m;j++)
			f[i][j]=min(f[i-1][j-1],f[i-1][j])+seq[j][i];
	}
	ans=INF;
	for(int i=1;i<=m;i++) ans=min(ans,f[n][i]);
	cout<<ans;
	return 0;
}
