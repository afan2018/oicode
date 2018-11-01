#include<cstdio>
using namespace std;
int num[10]={0},m=0,mask=0,sum=0;
int main()
{
	for(int i=1;i<=9;i++) scanf("%x",num+i);
	for(int i=0;i<32;i++)
	{
		sum=0;
		mask+=(1<<i);
		for(int j=1;j<=8;j++)
			sum+=((num[j]^m)&mask);
		if((sum&mask)!=((num[9]^m)&mask))
			m+=(1<<i);
	}
	printf("%x\n",m);
	return 0;
}
