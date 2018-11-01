#include<iostream>
using namespace std;
int n,m,cnt1=0,cnt2=0;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(i==j) cnt1+=(n-i+1)*(m-j+1);
			else cnt2+=(n-i+1)*(m-j+1);
	printf("%d %d",cnt1,cnt2);
	return 0;
}
