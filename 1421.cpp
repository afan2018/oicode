#include<cstdio>
int seq[15]={0},up,down,foo,bar;
inline int gcd(int a,int b)
{return b==0?a:gcd(b,a%b);}
int main()
{
	scanf("%d%d",&seq[1],&seq[2]);
	for(int i=3;i<=11;i++)
	{
		seq[i]=(seq[i-1]+seq[i-2])%4;
		for(int j=1;j<=i-3;j++)
		{
			if(seq[j]==seq[i-1]&&seq[j+1]==seq[i])
			{
				for(int k=1;k<=i-1-j;k++) down=down*10+9;
				for(int k=1;k<=j-1;k++)	down*=10;
				for(int k=1;k<=i-2;k++) up=up*10+seq[k];
				for(int k=1;k<=j-1;k++) foo=foo*10+seq[k];
				up-=foo;
				bar=gcd(up,down);
				printf("%d/%d",up/bar,down/bar);
				return 0;
			}
		}
	}
	return 0;
}
