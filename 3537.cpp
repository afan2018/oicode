#include<cstdio>
const int MOD=1000007;
int lim[105]={0},n,m,cnt=0,mem[105][105]={0};
int DFS(int x,int pos)
{
	if(mem[x][pos]) return mem[x][pos];
	if(x==n+1)//memorize
	{
		if(pos==m) return 1;
		return 0;
	}
	for(int i=0;i<=lim[x];i++)
	{
		if(pos+i>m) break;
		mem[x][pos]=(mem[x][pos]+DFS(x+1,pos+i))%MOD;
	}
	return mem[x][pos];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&lim[i]);
	printf("%d",DFS(1,0));
	return 0;
}