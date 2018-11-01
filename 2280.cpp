#include<iostream>
using namespace std;
int f[5][5]={0},lqxio[100005][5]={0},n,ans;
void dp(int idx)
{
	for(int i=1;i<=4;i++) f[1][i]=0;
	f[1][idx]=lqxio[1][idx/2+1];
	for(int i=2;i<=n;i++)
	{
		f[i%4][1]=max(f[(i-1)%4][3],f[(i-1)%4][4])+lqxio[i][1];
		f[i%4][2]=f[(i-1)%4][4]+lqxio[i][2];
		f[i%4][3]=f[(i-1)%4][1]+lqxio[i][2];
		f[i%4][4]=max(f[(i-1)%4][1],f[(i-1)%4][2])+lqxio[i][3];
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
			cin>>lqxio[i][j];
	dp(1);
	ans=max(f[n%4][3],f[n%4][4]);
	dp(2);
	ans=max(ans,f[n%4][4]);
	dp(3);
	ans=max(ans,f[n%4][1]);
	dp(4);
	if(max(f[n%4][1],f[n%4][2])>ans)ans=max(f[n%4][1],f[n%4][2]);
	cout<<ans;
	return 0;
}
