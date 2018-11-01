#include<iostream>
#include<cstdio>
using namespace std;
int sum[205][205]={0},d,n,maxx=0,maxy=0,ans[205][205]={0},cnt=0,mans=0;
int main()
{
	scanf("%d%d",&d,&n);
	int x,y,z;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		sum[++x][++y]=z;
	}
	for(int i=1;i<=(129+2*d);i++)
		for(int j=1;j<=(129+2*d);j++)
			sum[i][j]=sum[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	for(int i=d+1;i<=(129+d);i++)
		for(int j=d+1;j<=(129+d);j++)
		{
			ans[i][j]=sum[i][j]-sum[max(i-2*d-1,0)][j]-sum[i][max(j-2*d-1,0)]+sum[max(i-2*d-1,0)][max(j-2*d-1,0)];
			if(mans==ans[i][j]) cnt++;
			if(mans<ans[i][j])
			{
				mans=ans[i][j];
				cnt=1;
			}
		}
	printf("%d %d\n",cnt,mans);
	return 0;
}