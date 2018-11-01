#include<cstdio>
struct node{int x,y,a,b;}Carpet[10005];
int n,Qx,Qy,ans=-1;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d%d",&Carpet[i].x,&Carpet[i].y,&Carpet[i].a,&Carpet[i].b);
	scanf("%d%d",&Qx,&Qy);
	for(int i=1;i<=n;i++)
		if(Qx>=Carpet[i].x&&Qx<=Carpet[i].x+Carpet[i].a&&Qy>=Carpet[i].y&&Qy<=Carpet[i].y+Carpet[i].b)
			ans=i;
	printf("%d",ans);
	return 0;
}