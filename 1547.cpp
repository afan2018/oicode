#include<iostream>
using namespace std;
int main()
{
	int a[15][15]={0},n;
	a[1][1]=1;a[2][1]=1;a[2][2]=1;
	for(int i=3;i<=10;i++)
	{
		a[i][1]=1;a[i][i]=1;
		for(int j=1;j<=10;j++)
		a[i][j]=a[i-1][j-1]+a[i-1][j];
	}
	cin>>n;
	for(int i=1;i<=n;i++)
 	   {
			for(int j=1;j<=i;j++)	
			cout<<a[i][j]<<" ";
			cout<<endl;
	   }
	return 0;
}
