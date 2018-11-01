#include<iostream>
using namespace std;
int main(){
	char num[45];
	int val[45][45]={0},res[45][10]={0},n,m;
	cin>>n>>m;
	getchar();
	for(int i=1;i<=n;i++)
		num[i]=getchar();
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			int o=1;
			for(int q=j;q>=i;q--)
			{
				val[i][j]+=int(num[q]-'0')*o;
				o*=10;
			}	
		}
	for(int i=1;i<=n;i++)
		res[i][0]=val[1][i];
	for(int i=1;i<=m;i++)
		for(int j=i+1;j<=n;j++)
		{
			for(int q=i;q<=j-1;q++)
				res[j][i]=max(res[j][i],val[q+1][j]*res[q][i-1]);
		}
	cout<<res[n][m];
	return 0;
}