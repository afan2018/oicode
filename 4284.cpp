#include<cstdio>
const int Table[5][5][2]=//0 A 1 B
{{{0,0},{0,1},{1,0},{1,0},{0,1}},
{{1,0},{0,0},{0,1},{1,0},{0,1}},
{{0,1},{1,0},{0,0},{0,1},{1,0}},
{{0,1},{0,1},{1,0},{0,0},{1,0}},
{{1,0},{1,0},{0,1},{0,1},{0,0}}};
int n,ta,tb,seqa[205]={0},seqb[205]={0},cnt,pa,pb,ansa=0,ansb=0;
int main()
{
	scanf("%d%d%d",&n,&ta,&tb);
	for(int i=1;i<=ta;i++) scanf("%d",seqa+i);
	for(int i=1;i<=tb;i++) scanf("%d",seqb+i);
	pa=1,pb=1,cnt=0;
	while(++cnt<=n)
	{
		if(pa>ta) pa=1;
		if(pb>tb) pb=1;
		ansa+=Table[seqa[pa]][seqb[pb]][0];
		ansb+=Table[seqa[pa]][seqb[pb]][1];
		pa++;
		pb++;
	}
	printf("%d %d",ansa,ansb);
	return 0;
}