#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,m;
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(!n&&!m) return 0;
		n*=100;
		for(int i=0;i<=99;i++)
			if((n+i)%m==0) printf("%d%d ",i/10,i%10);
		printf("\n");
	}
	return 0;
}
