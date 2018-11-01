#include<cstdio>
#include<algorithm>
int seq[10005]={0},n,m,cnt=0;;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",seq+i);
	while(std::next_permutation(seq+1,seq+n+1))
	{
		cnt++;
		if(cnt==m)
		{
			for(int i=1;i<=n;i++)
				printf("%d ",seq[i]);
			return 0;
		}
	}
}