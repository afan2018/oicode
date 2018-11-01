#include<iostream>
const int INF=0x3f3f3f3f;
using namespace std;
int f[1005][1005]={0},sum[1005][2]={0},n,k;
char ch;
int main(){
	cin>>n>>k;
	for(int i=2;i<=k;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=INF;
	for(int i=1;i<=n;i++)
	{
		sum[i][0]=sum[i-1][0];
		sum[i][1]=sum[i-1][1];
		cin>>ch;
		if(ch=='0') sum[i][0]++;
		else sum[i][1]++; 
	}
	for(int i=1;i<=n;i++)
		f[1][i]=sum[i][0]*sum[i][1];
	for(int i=2;i<=k;i++)
	{
		f[i][i]=0;
		for(int j=i;j<=n;j++)
			for(int k=i-1;k<j;k++)
				f[i][j]=min(f[i][j],f[i-1][k]+(sum[j][0]-sum[k][0])*(sum[j][1]-sum[k][1]));
	}
	cout<<f[k][n];
	return 0;
}
