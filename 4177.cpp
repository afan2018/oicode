#include<iostream>
const int mod=10007;
using namespace std;
int ans=1,n,m,com[10001][101];
void YH()
{
	for(int i=1;i<=n;i++) com[i][1]=i;
	for(int i=2;i<=n;i++)
		for(int j=2;j<=100;j++)
		{
   			if(i==j) com[i][j]=1;
    		if(i<=j) break;
    		com[i][j]=(com[i-1][j-1]+com[i-1][j])%mod;
   		}
}
int main()
{
	cin>>n>>m;
	YH();
 	for(int i=1,x;i<=m;i++)
 	{
	 	cin>>x;
  		if(x) ans=(ans*com[n][x])%mod;
  		n-=x;
 	}
	cout<<ans<<'\n';
 	return 0;
}