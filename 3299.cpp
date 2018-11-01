#include <cstdio>
#include <cstring>
const int MaxLength=40;
const int MaxValue=100000;
const int INF=(0x7ffffff);
int num[MaxLength+5][MaxLength+5],aim,len,f[MaxLength+5][MaxValue+5],rec[MaxLength+5][MaxValue+5];;
char s[MaxLength+5];
void Init()
{
	scanf("%s%d",&s,&aim);
	len=strlen(s);
	for(int i=1;i<=len;i++) num[i][i]=s[i-1]-'0';
	for(int i=1;i<=len-1;i++)
	for(int j=i+1;j<=len;j++)
		{
			num[i][j]=num[i][j-1]*10+num[j][j];
			if(num[i][j]>MaxValue) num[i][j]=MaxValue;
		}
	return;
}
void Dp_Backpack()
{
	for(int i=0;i<=len;i++)
		for(int j=0;j<=MaxValue;j++)
			rec[i][j]=INF;
	rec[0][0]=0;
	f[0][0]=true;
	for(int i=1;i<=len;i++)
		for(int j=1;j<=i;j++)
        {
			if(num[i-j+1][i]>MaxValue) break;
			for(int k=0;k<=MaxValue;k++)
		 	if(f[i-j][k])
			{
				f[i][k+num[i-j+1][i]]=true;    
				if(rec[i][k+num[i-j+1][i]]>rec[i-j][k]+1) rec[i][k+num[i-j+1][i]]=rec[i-j][k]+1;
			}
		}
	if(rec[len][aim]!=INF) printf("%d",rec[len][aim]-1);
	else printf("-1");
	return;
}
int main()
{
	Init();
	Dp_Backpack();
	return 0;
}