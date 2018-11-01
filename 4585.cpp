#include<iostream>
#include<cstring>
const int INF=0x3f3f3f3f;
using namespace std;
int r[205][205]={0},n,f[205]={0};
int main(){
	cin>>n;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			cin>>r[i][j];
	memset(f,INF,sizeof(f));
	f[1]=0;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i-1;j++)
			f[i]=min(f[i],f[j]+r[j][i]);
	cout<<f[n];
	return 0;
}
