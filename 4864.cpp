#include<cstdio>
#include<cstring>
int n,seq[1005][35]={{0}},ori[5]={0},fl[5]={0},minn=0,st=-1,ed=-1,ans[35]={0},mask[35]={0};
int Getint()
{
	int fl=1,ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') fl=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*fl;
}
void Output(int s[])
{
	for(int i=1;i<=4;i++)
	{
		int sum=0;
		for(int j=i*8;j>=(i-1)*8+1;j--)
			sum+=s[j]*(1<<(8-j+(i-1)*8));
		printf("%d",sum);
		if(i!=4) printf(".");
	}
}
int main()
{
	n=Getint();
	memset(ori,-1,sizeof(ori));
	for(int i=1;i<=4;i++) fl[i]=1;
	for(int i=1,x,cnt;i<=n;i++)
	{
		cnt=0;
		for(int j=1;j<=4;j++)
		{
			x=Getint();
			if(ori[j]==-1) ori[j]=x;
			else if(x!=ori[j]) fl[j]=0;
			for(int k=7;k>=0;k--) seq[i][++cnt]=(x&(1<<k))==(1<<k);
		}
	}
	for(int i=1;i<=4;i++)
		if(fl[i]==0)
		{
			st=i;
			break;
		}
	if(st==-1)
	{
		Output(seq[1]);
		puts("\n255.255.255.255");
		return 0;
	}
	for(int i=(st-1)*8;i<=32;i++)
	{
		for(int j=1;j<n;j++)
			if(seq[j][i]!=seq[j+1][i])
			{
				ed=i-1;
				break;
			}
		if(ed!=-1) break;
	}
	for(int i=1;i<=ed;i++)
	{
		ans[i]=seq[1][i];
		mask[i]=1;
	}
	for(int i=ed+1;i<=32;i++) ans[i]=mask[i]=0;
	Output(ans);
	puts("");
	Output(mask);
	return 0;
}