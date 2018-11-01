#include<iostream>
#include<algorithm>
#include<cstring>
const int INF=0x3f3f3f3f;
using namespace std;
int maxx=0,s[100005]={0},sou=0,g1[1005][1005],g2[1005][1005]={0},dis1[100005]={0},prt[100005]={0},n,m,dis2[100005]={0};
void Dijkestra(int v0,int d[],int g[][1005])
{
	int k,minn;
	memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++)d[i]=INF;
	d[v0]=0;
	for(int i=1;i<=n;i++)
	{  
		minn=INF;  
		for(int j=1;j<=n;j++) 
		if(s[j]==0&&minn>d[j]){minn=d[j];k=j;}
		s[k]=1; 
		for(int j=1;j<=n;j++) 
			if(g[k][j]<INF&&!s[j]&&d[k]+g[k][j]<d[j])
				d[j]=d[k]+g[k][j];
    }
}
int main(){
	cin>>n>>m>>sou;
	memset(g1,INF,sizeof(g1));
	memset(g2,INF,sizeof(g2));
	for(int i=1,a,b,c;i<=m;i++)
	{
		cin>>a>>b>>c;
		if(g1[a][b]) g1[a][b]=min(g1[a][b],c);
		else g1[a][b]=c;
	}
	Dijkestra(sou,dis1,g1);	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(g1[i][j]<INF) g2[j][i]=g1[i][j];
	Dijkestra(sou,dis2,g2);
	for(int i=1;i<=n;i++)
		dis1[i]+=dis2[i];
	for(int i=1;i<=n;i++)
		if(dis1[i]<INF) maxx=max(dis1[i],maxx);
	cout<<maxx;
	return 0;
}
