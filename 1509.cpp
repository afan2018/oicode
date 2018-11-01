#include<cstdio>
int s,t,w,seq[1005],n;
char buffer[1005];
int main()
{
	scanf("%d%d%d%s",&s,&t,&w,buffer);
	for(int i=0;i<w;i++) seq[i+1]=buffer[i]-'a'+1;
	for(int i=1;i<=5;i++)
	{
		int pos=0;
		for(int j=w;j>=1;j--)
			if(seq[j]!=t-(w-j)) {pos=j;break;}
		if(pos==0) break;
		seq[pos]++;
		for(int j=pos+1;j<=w;j++)
			seq[j]=seq[j-1]+1;
		for(int j=1;j<=w;j++)
			printf("%c",char(seq[j]+'a'-1));
		printf("\n");
	}
	return 0;
}